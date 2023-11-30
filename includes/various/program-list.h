#
/*
 *    Copyright (C) 2014
 *    Jan van Katwijk (J.vanKatwijk@gmail.com)
 *    Lazy Chair Computing
 *
 *    This file is part of the fmreceiver
 *
 *    fmreceiver is free software; you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation; either version 2 of the License, or
 *    (at your option) any later version.
 *
 *    fmreceiver is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with DAB-library; if not, write to the Free Software
 *    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#pragma once

#include	<QWidget>
#include	<QScrollArea>
#include	<QTableWidget>
#include	<QStringList>
#include	<QTableWidgetItem>
#include	<QObject>
#include	<QString>

class	RadioInterface;

class	programList:public QObject {
Q_OBJECT
public:
			programList	(RadioInterface *,
	                                 const QString &, QScrollArea *);
			~programList	();
	void		addRow		(const QString &, const QString &);
	void		loadTable	();
	void		saveTable	();
private slots:
	void		tableSelect	(int, int);
	void		removeRow	(int, int);
signals:
	void		newFrequency	(int);
	void		insertRow	(int);
	void		removeRow	(int);
	void		resizeColumnsToContents ();
private:
	RadioInterface		*myParent;
	QScrollArea		*myWidget;
	QTableWidget		*tableWidget;
	QString			saveName;
};

