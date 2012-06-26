#ifndef HTMLTABLE_H
#define HTMLTABLE_H
#include <vector>
#include <string>


class TableRow {
public:
//  void add
private:
  std::vector<std::string> row;
};

class HtmlTable {
public:
  HtmlTable();

private:
  std::vector<std::string> headers;
  std::vector<TableRow> rows;
};

#endif // HTMLTABLE_H
