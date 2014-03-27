#ifndef _HOYGAN_H
#define _HOYGAN_H

#include <QString>
#include <QRegExp>
#include <cstdlib>
#include "dicsionario.h"

class Hoygan
{
public:
	Hoygan( const QString& horiginal );
	QString traduse();

	
private:
	QString eliminaCaracteresProibidos();
	QString traducsionDicsionario();
	QString manejoGJ();
	QString manejoYLL();
	QString manejoCS();
	QString	manejoAche();
	QString teclaEncayada( bool aleatorio=true );


	QString horiginal;
	QString traducsion;
	QString puntuasion;
	Dicsionario dicsionario;
};

#endif