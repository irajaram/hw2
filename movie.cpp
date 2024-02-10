#include "movie.h"
#include "util.h"
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;
Movie::Movie(const std::string category, const std::string name, double price, int qty, const std::string genre, const std::string rating):
 Product(category,name,price,qty) {
    genre_ = genre;
    rating_ = rating;

}

Movie::~Movie(){
    
}
 std::set<std::string> Movie:: keywords() const{
    set<std::string> result;
    result = parseStringToWords(name_);
    /*for(typename std::set<std::string>::iterator it=prodName.begin();it != prodName.end();++it){
        result.insert(*it);
    }*/
    result.insert(convToLower(genre_));
    return result;
        
}

 std::string Movie::displayString() const{
  std::ostringstream fullProdinfo;
    fullProdinfo<< name_ << "\n" << "Genre: " << genre_ << " Rating: " << rating_ << "\n"
    << fixed << setprecision(2) << price_ << " " <<qty_ << " left." << "\n";
    return fullProdinfo.str();

}

void Movie::dump(std::ostream& os) const {
    Product::dump(os);
    os << genre_ << "\n" << rating_ << "\n";
}