#include "hoygan.h"


Hoygan::Hoygan( const QString& original )
{
	horiginal = original;

	int pos;
	if( ((pos=QRegExp("!+$").indexIn( horiginal,0))!=-1)
				|| ((pos=QRegExp("\\?+$").indexIn( horiginal,0))!=-1)
				|| ((pos=QRegExp("\\.+$").indexIn( horiginal,0))!=-1)
				|| ((pos=QRegExp(",+$").indexIn( horiginal,0))!=-1)

				)
	{
		puntuasion = horiginal.mid( pos, horiginal.size()-1 );
	}

	traducsion = horiginal.mid( 0, pos ).toUpper();
}


QString Hoygan::traduse()
{
	this->eliminaCaracteresProibidos();
	this->manejoGJ();
	this->manejoYLL();
	this->manejoCS();
	this->manejoAche();
	
	this->traducsionDicsionario();
	this->teclaEncayada( true );
	
	if( !puntuasion.isEmpty() )
	{
		if( puntuasion.contains("!") )
		{
			puntuasion = "!!!!!!1!111111";
		}
		
		traducsion+= puntuasion;
	}
	
	return traducsion;
}


QString Hoygan::eliminaCaracteresProibidos()
{
	if( traducsion.isEmpty() )
		return QString();

	traducsion.replace( "á","A", Qt::CaseInsensitive );
	traducsion.replace( "à","A", Qt::CaseInsensitive );
	traducsion.replace( "é","E", Qt::CaseInsensitive );
	traducsion.replace( "è","E", Qt::CaseInsensitive );
	traducsion.replace( "ó","O", Qt::CaseInsensitive );
	traducsion.replace( "ò","O", Qt::CaseInsensitive );
	traducsion.replace( "í","I", Qt::CaseInsensitive );
	traducsion.replace( "ì","I", Qt::CaseInsensitive );
	traducsion.replace( "ú","U", Qt::CaseInsensitive );
	traducsion.replace( "ù","U", Qt::CaseInsensitive );

	return traducsion;
}



QString Hoygan::traducsionDicsionario()
{
	if( dicsionario.existe( traducsion ) )
	{
		traducsion = dicsionario.traduse(traducsion);
	}
	
	return traducsion;
}


QString Hoygan::manejoGJ()
{
	QRegExp rx("aga|age|agi|agu|ega|ege|egi|ego|iga|ige|igo|igu|igi|uga|uge|ugi|ugo|oga|oge|ogi|ogu|ogo", Qt::CaseInsensitive );

	int pos = 0;
	QStringList list;

	while( (pos = rx.indexIn(traducsion, pos)) != -1 )
	{
		QString match = rx.cap(0);
		QString correcsion = match;
		correcsion.replace("g","J", Qt::CaseInsensitive );

		pos += rx.matchedLength();

		traducsion = traducsion.replace( match, correcsion, Qt::CaseInsensitive );
	}

	return traducsion;
}


QString Hoygan::manejoYLL()
{
	QRegExp rx("aya|aye|ayi|ayu|eya|eye|eyi|eyo|iya|iye|iyo|iyu|iyi|uya|uye|uyi|uyo|oya|oye|oyi|oyu|oyo", Qt::CaseInsensitive );

	int pos = 0;
	QStringList list;
	while( (pos = rx.indexIn(traducsion, pos)) != -1 )
	{
		QString match = rx.cap(0);
		QString correcsion = match;
		correcsion.replace("y","LL", Qt::CaseInsensitive );

		pos += rx.matchedLength();

		traducsion = traducsion.replace( match, correcsion, Qt::CaseInsensitive );
	}

	return traducsion;
}


QString Hoygan::manejoCS()
{
	QRegExp rx("ace|aci|ece|eci|ice|ici|uce|uci|oce|oci|^ce|nci", Qt::CaseInsensitive );

	int pos = 0;
	QStringList list;
	while( (pos = rx.indexIn(traducsion, pos)) != -1 )
	{
		QString match = rx.cap(0);
		QString correcsion = match;
		correcsion.replace("c","S", Qt::CaseInsensitive );

		pos += rx.matchedLength();

		traducsion = traducsion.replace( match, correcsion, Qt::CaseInsensitive );
	}

	return traducsion;
}


QString Hoygan::manejoAche()
{
	unsigned char apply = 0+4*((float)qrand()) / RAND_MAX;

	if( (apply%3)==0 )
	{
		QRegExp rx("^[aeiou]", Qt::CaseInsensitive );
		if( rx.indexIn( traducsion, 0 )!=-1 )
		{
			traducsion = "H"+traducsion;
		}
	}
	
	return traducsion;
}



QString Hoygan::teclaEncayada( bool aleatorio )
{
	unsigned char aplical = 1;
	if( aleatorio )
	{
		aplical = 0+25*((float)qrand()) / RAND_MAX;
		if( (aplical%3)==0 )
		{
			aplical = 1;
		}
		else
			aplical = 0;
	}


	if( aplical && traducsion.size()>3 )
	{
		unsigned char repetitions = 0+3*((float)qrand()) / RAND_MAX;

		for( unsigned char i=0; i<repetitions; i++ )
		{
			traducsion+= traducsion[ traducsion.size()-1 ];
		}
	}
	return traducsion;
}
