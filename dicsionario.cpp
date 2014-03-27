#include "dicsionario.h"
#include <QDebug>

Dicsionario::Dicsionario()
{
}

void Dicsionario::carga( const QString& path )
{
	QSettings::setPath( QSettings::IniFormat, QSettings::UserScope, "./" );
	QSettings settings( path, QSettings::IniFormat );
	
	settings.beginGroup("dicsionario");
	QStringList words = settings.allKeys();
	
	foreach( QString word, words )
	{
		palabras.insert( word.toUpper(), settings.value( word ).toString().toUpper() );
//		qDebug() << word << "=" << settings.value( word ).toString();
	}
	settings.endGroup();
}


bool Dicsionario::existe( const QString& word ) const
{
	return palabras.contains( word );
}
	
	
QString Dicsionario::traduse( const QString& word ) const
{
	if( palabras.contains( word ) )
	{
		return palabras.value(word);
	}
	else
		return word;
}
