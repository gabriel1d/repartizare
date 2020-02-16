#ifndef CSVPARSER_HPP
#define CSVPARSER_HPP

#include <string>
#include <vector>
#include <fstream>
#include <boost/algorithm/string.hpp>

class CsvParser {
public:
    CsvParser(const std::string &mNameFile);

    bool parseRow(std::vector<std::wstring>& result);

    ~CsvParser();

    template<typename ColType>
    bool headerMatchesInputHeader(const ColType& collumnElement);

    template<typename T,typename... Cols>
    bool headerMatchesInputHeader(const T& first, const Cols& ... cols);

private:
    std::string mInputFileName;
    FILE* mInputFile;
    std::vector<std::wstring> mHeaderVector;
public:
    const std::vector<std::wstring> &getMHeaderVector() const;

private:

    bool replaceCommaWithFullStopForLine(std::wstring& line);
};

CsvParser::CsvParser(const std::string &mNameFile) : mInputFileName(mNameFile)
{
    char *locale = setlocale(LC_ALL, "");
    mInputFile = fopen(mNameFile.c_str(), "r");
    parseRow(mHeaderVector);
}

CsvParser::~CsvParser()
{
    fclose(mInputFile);
};

bool CsvParser::replaceCommaWithFullStopForLine(std::wstring& line)
{
    // replace floatingPoint
    auto firstDelimiterForNota = LR"(,")";
    std::size_t foundFirstDelimiter = line.find(firstDelimiterForNota);
    if (foundFirstDelimiter !=std::string::npos) {
        // get last character from found wstringScore and check if the wstringScore is "100,00" or lower 10.02/
        auto lastCharacterOfScore = line.substr(foundFirstDelimiter + 7, 1);
        if (lastCharacterOfScore != L"0") {
            line.replace(foundFirstDelimiter + 1 , 1, L"");
            line.replace( foundFirstDelimiter + 6,1, L"");
            line.replace(foundFirstDelimiter + 3, 1, L".");
        } else
        {
            line.replace(foundFirstDelimiter + 1 , 1, L"");
            line.replace( foundFirstDelimiter + 7,1, L"");
            line.replace(foundFirstDelimiter + 4, 1, L".");
        }
        return true;
    }
    return false;
}

bool CsvParser::parseRow(std::vector<std::wstring>& result)
{
    wint_t characterfromFile{};
    std::wstring stringLine{};

    do
    {
        characterfromFile = fgetwc(mInputFile);
        if(characterfromFile == L'\r')
            stringLine.erase( std::remove(stringLine.begin(), stringLine.end(), L'\r'), stringLine.end());
        else {
            if (characterfromFile == WEOF)
                return false;
            else
                stringLine += characterfromFile;
        }
    }while(characterfromFile != L'\r');

    replaceCommaWithFullStopForLine(stringLine);
    boost::split(result,stringLine,boost::is_any_of(L","));

    return true;
}

template<typename CollumnType>
bool CsvParser::headerMatchesInputHeader(const CollumnType& collumnElement)
{
    bool bIsElementOfHeader = false;
    for(auto const& headerElement : mHeaderVector)
        if(headerElement == collumnElement)
            bIsElementOfHeader = true;

    if(!bIsElementOfHeader)
        wprintf(L"\nThe Requested < %ls > collumn is not found in the header of the %s\n", collumnElement, mInputFileName.c_str());

    return bIsElementOfHeader;
}

template<typename T,typename... Cols>
bool CsvParser::headerMatchesInputHeader(const T& first, const Cols& ... cols)
{
    bool bIsElementOfHeader = false;
    for(auto const& headerElement : mHeaderVector)
        if(headerElement == first)
            bIsElementOfHeader = true;

    if(!bIsElementOfHeader)
        wprintf(L"\nThe Requested < %ls > collumn is not found in the header of the %s\n", first, mInputFileName.c_str());

    return bIsElementOfHeader && headerMatchesInputHeader(cols...);
}

const std::vector<std::wstring> &CsvParser::getMHeaderVector() const {
    return mHeaderVector;
}

#endif // CSVPARSER_HPP
