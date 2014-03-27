#ifndef _DICSIONARIO_H
#define _DICSIONARIO_H

#include <QSettings>
#include <QString>
#include <QStringList>
#include <QMap>

class Dicsionario
{
public:
	Dicsionario();
	void carga( const QString& path );
	bool existe( const QString& word ) const;
	QString traduse( const QString& word ) const;

private:
	QMap<QString,QString> palabras;
};

#endif
