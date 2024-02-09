#include "clothing.h"
#include "util.h"
#include <iostream>
using namespace std;
Clothing::Clothing(const std::string category, const std::string name, double price, int qty, const std::string size, const std::string brand):
 Product(category,name,price,qty) {
    size_ = size;
    brand_ = brand;

}
Clothing::~Clothing(){
    
}
 std::set<std::string> Clothing:: keywords() const{
    set<std::string> result;
    set<std::string> brandName;
    set<std::string> prodName;
    prodName = parseStringToWords(name_);
    for(typename std::set<std::string>::iterator it=prodName.begin();it != prodName.end();++it){
        result.insert(*it);
    }
    brandName = parseStringToWords(brand_);
    for(typename std::set<std::string>::iterator it=brandName.begin();it != brandName.end();++it){
        result.insert(*it);
    }
    result.insert(size_);
    return result;
        
}

 std::string Clothing::displayString() const{
    std::string fullProdinfo="";
    fullProdinfo+= name_ + "\n"+"Size: " + size_ + " Brand: " + brand_ + "\n";
    fullProdinfo+= to_string(price_) + " " + to_string(qty_) + " left." + "\n";
    return fullProdinfo;

}

void Clothing::dump(std::ostream& os) const {
    Product::dump(os);
    os << size_ << "\n" << brand_ << "\n" << endl;
}