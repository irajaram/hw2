#include "book.h"
#include "util.h"
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;
Book::Book(const std::string category, const std::string name, double price, int qty, const std::string authorname, const std::string ISBN):
 Product(category,name,price,qty) {
    author_ = authorname;
    isbn_ = ISBN;

}

Book::~Book(){
    
}
 std::set<std::string> Book:: keywords() const{
    set<std::string> result;
    set<std::string> atname;
    set<std::string> prodName;
    prodName = parseStringToWords(name_);
    
    /*for(typename std::set<std::string>::iterator it=prodName.begin();it != prodName.end();++it){
        result.insert(*it);
    }*/
    atname = parseStringToWords(author_);
    /*for(typename std::set<std::string>::iterator it=atname.begin();it != atname.end();++it){
        result.insert(*it);
    }*/
    result = setUnion(prodName,atname);
    result.insert(isbn_);
    return result;
        
}

 std::string Book::displayString() const{
    std::ostringstream fullProdinfo;
    fullProdinfo<< name_ << "\n" << "Author: " << author_ << " ISBN: " << isbn_ << "\n"
    << fixed << setprecision(2) << price_ << " " <<qty_ << " left." << "\n";
    return fullProdinfo.str();

}

void Book::dump(std::ostream& os) const {
    Product::dump(os);
    os << isbn_ << "\n" << author_ << "\n";
}