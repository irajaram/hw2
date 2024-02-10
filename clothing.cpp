#include "clothing.h"
#include "util.h"
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;
Clothing::Clothing(const std::string category, const std::string name, double price, int qty, const std::string size, const std::string brand):
 Product(category,name,price,qty) {
    size_ = size;
    brand_ = brand;

}
Clothing::~Clothing(){
    
}
 std::set<std::string> Clothing::keywords() const{
    set<std::string> result;
    set<std::string> brandName;
    set<std::string> prodName;
    prodName = parseStringToWords(name_); 
    brandName = parseStringToWords(brand_);
    result = setUnion(prodName,brandName);
    return result;
        
}

 std::string Clothing::displayString() const{

    std::ostringstream fullProdinfo;
    fullProdinfo<< name_ << "\n" << "Size: " << size_ << " Brand: " << brand_ << "\n"
    << fixed << setprecision(2) << price_ << " " <<qty_ << " left." << "\n";
    return fullProdinfo.str();

}

void Clothing::dump(std::ostream& os) const {
    Product::dump(os);
    os << size_ << "\n" << brand_ << "\n";
}