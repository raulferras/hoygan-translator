#include "mainwindow.h"
#include "hoygan.h"
#include <QSettings>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent)
{
    setupUi(this);

	//Beamoss el dicsionario sista disphonible
	dicsionario.carga( "dicsionario.ini" );
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_pushButton_released()
{
	translate();
}




void MainWindow::translate()
{
//	qsrand(1928332);

	QString original = plainTextEdit_original->toPlainText();
	QStringList lines = original.split("\n");
	unsigned int lines_c = lines.size();
	QString translation;

	for( unsigned int l=0; l<lines_c; l++ )
	{
		QStringList words = lines[l].split(" ");
		unsigned int words_c = words.size();

		//Manipulasion por palabra
		for( unsigned int i=0; i<words_c; i++ )
		{
			Hoygan hoygan( words[i] );
			
			words[i] = hoygan.traduse();
			/*
			QString punct;
			//# aplicamos un proseso inisial

			//gualdal el ultimo sibno de punstuasion
			int pos;
			if( ((pos=QRegExp("!+$").indexIn(words[i],0))!=-1)
				|| ((pos=QRegExp("\\?+$").indexIn(words[i],0))!=-1)
				|| ((pos=QRegExp("\\.+$").indexIn(words[i],0))!=-1)
				|| ((pos=QRegExp(",+$").indexIn(words[i],0))!=-1)

				)
			{
				punct = words[i].mid( pos, words[i].size()-1 );
				words[i] = words[i].mid( 0, pos );
			}
			words[i] = hoygan.init( words[i] );


			//# avientamos los caracteress proibidos ene lidioma.
			words[i] = hoygan.forbiddenCharacters( words[i] );

			//# sustitusion de g's por j
			words[i] = hoygan.traduseGJ( words[i] );
			words[i] = hoygan.traduseYLL( words[i] );
			words[i] = hoygan.traduseCS( words[i] );

			//# Anadimos H's donde no tocan
			words[i] = hoygan.anadeAche( words[i] );

			//# Mira sies una palabra en el dicsionario que se traduse
			// de forma arbitraria
			words[i] = hoygan.usaDicsionario( dicsionario, words[i] );


			//# Sindrome de la tecla encallada:
			// Aplicamos el sindrome de la tecla encallada
			// al final de una palabra.
			// La palabra que sufra del sindrome es escogida aleatoriamente
			unsigned char apply = 0+25*((float)qrand()) / RAND_MAX;
			if( (apply%3)==0 )
			{
				words[i] = hoygan.sindromeTeclaEncallada( words[i] );
			}

			if( !punct.isEmpty() )
			{
				if( punct.contains("!") )
				{
					punct="!!!!!!1!111111";
				}
				words[i]+= punct;
			}
			*/
			//End line -

		}
		qDebug() << words.join(" ");
		translation+= words.join(" ")+"\n";
	}

	translated->setPlainText( translation );
}
