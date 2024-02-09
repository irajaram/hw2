#include "movie.h"
#include "util.h"
#include <iostream>
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
    set<std::string> atname;
    set<std::string> prodName;
    prodName = parseStringToWords(name_);
    for(typename std::set<std::string>::iterator it=prodName.begin();it != prodName.end();++it){
        result.insert(*it);
    }
    result.insert(genre_);
    result.insert(rating_);
    return result;
        
}

 std::string Movie::displayString() const{
    std::string fullProdinfo="";
    fullProdinfo+= name_ + "\n"+"Genre: " + genre_ + " Rating: " + rating_ + "\n";
    fullProdinfo+= to_string(price_) + " " + to_string(qty_) + " left." + "\n";
    return fullProdinfo;

}

void Movie::dump(std::ostream& os) const {
    Product::dump(os);
    os << genre_ << "\n" << rating_ << "\n" << endl;
}