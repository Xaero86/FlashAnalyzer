#ifndef EXTRACTABLETAG_H
#define EXTRACTABLETAG_H

#include <string>
#include <fstream>

class ExtractableTag
{
public:
	virtual std::string extensionFile() const = 0;
	virtual void extract(std::ofstream& outputFile) = 0;
};

#endif // EXTRACTABLETAG_H
