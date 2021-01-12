#include "rawdatawidget.h"

#include <sstream>
#include <iomanip>

RawDataWidget::RawDataWidget(QWidget *parent)
 : QTextEdit(parent)
{
	setWindowTitle("Raw data");
	QFont font = document()->defaultFont();
	font.setFamily("Courier New");
	document()->setDefaultFont(font);
	setReadOnly(true);
	resize(400,300);
}

void RawDataWidget::setData(const char* data, unsigned int size)
{
	std::stringstream output;
	unsigned int currentIndex = 0;

	output << std::hex;

	while (currentIndex < size)
	{
		output << std::hex << std::setw(2) << +((unsigned char)data[currentIndex]) << " ";
		if (currentIndex%16 == 15)
		{
			output << std::endl;
		}
		currentIndex++;
	}
	setText(QString::fromStdString(output.str()));
}
