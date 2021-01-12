#ifndef RAWDATAWIDGET_H
#define RAWDATAWIDGET_H

#include <QtWidgets>

class RawDataWidget : public QTextEdit
{
public:
	RawDataWidget(QWidget *parent = nullptr);

	void setData(const char* data, unsigned int size);
};

#endif // RAWDATAWIDGET_H
