#include "mydatastore.h"
#include "util.h"
#include "product.h"
#include <set>
#include <iostream>
#include <queue>
using namespace std;


MyDataStore::MyDataStore() {

}

MyDataStore::~MyDataStore() {
   ;
    for( std::map<std::string,Product*>::iterator it=productsList.begin(); it!=productsList.end();it++){
        delete it->second;
    }
    for( std::map<std::string,User*>::iterator it=usersList.begin(); it!=usersList.end();it++){
        delete it->second;
    }
    
}

void MyDataStore::addProduct(Product* p){
    std::set <string> allKeyWords = p->keywords(); //get keywords, store in empty set
    for(std::set<string>::iterator it=allKeyWords.begin();it != allKeyWords.end();++it){ //iterate through set of keywords
       fullProd[*it].insert(p);  
       //cout << "adding " << p->getName() << " to keyword " << *it << endl;  
    }
    productsList.insert(std::make_pair(p->getName(),p));
}

void MyDataStore::addUser(User* u) {
    std::queue<Product*> userProducts;
    usersList.insert(std::make_pair(u->getName(), u));
    prodCart[u->getName()] = userProducts;
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type){
    vector<Product*> emptyVector;
    std::set <Product*> prodSet1 = fullProd[terms[0]];
    if(terms.size()==0){
        return emptyVector;
    } 
    //AND =0 and OR = 1
    for(int i=1; i<terms.size(); i++){
      if(type==0){
        prodSet1 = setIntersection(prodSet1,fullProd[terms[i]]);
      }

      else if(type==1){
        prodSet1 = setUnion(prodSet1,fullProd[terms[i]]);  
      }
    }

    for (std::set<Product *>::iterator it = prodSet1.begin(); it != prodSet1.end(); it++){
      emptyVector.push_back(*it);
    }
    return emptyVector;
}

void MyDataStore::addtoCart(const std::string& userName,Product* prod){
    if(usersList.find(userName)==usersList.end()){
        cout<< "Invalid request";
        return;
    }
    else {
        //inserts into 
        prodCart[userName].push(prod);
    }

}

void MyDataStore::viewCart(const std::string& username){
    int counter = 1;
    if(usersList.find(username)==usersList.end()){
        cout << "Invalid username" << endl;
        return;
    }
    else{
        queue <Product*> currProduct = prodCart[username];
        while(!currProduct.empty()){
            cout << "Item " << counter ++ << "\n";
            cout<< currProduct.front() -> displayString() << endl;
            currProduct.pop();
        }
    }
}

void MyDataStore::buyCart(const std::string& username) {
    if (usersList.find(username) == usersList.end()) {
      cout << "Invalid username" << endl;
      return;
    } 
    else {
      queue<Product*> &currProduct = prodCart[username];
      queue<Product*> temp;
      while (!currProduct.empty()) {
          Product* prodHold = currProduct.front();
          if (prodHold->getQty() > 0 && usersList[username]->getBalance() >= prodHold->getPrice()) {
            usersList[username]->deductAmount(prodHold->getPrice());
            prodHold->subtractQty(1);
            if (prodHold->getQty() > 0) {
                temp.push(prodHold);
            }
          }
          currProduct.pop();
      }
      // Update prodCart with the modified queue
      prodCart[username] = temp;
    }
    
    
}


void MyDataStore::dump(std::ostream& ofile){
    ofile << "<products>" << std::endl;
    for (std::map<std::string, Product*>::iterator it = productsList.begin(); it != productsList.end(); it++)
    {
        ((it)->second)->dump(ofile);
    }
    ofile << "</products>" << std::endl;
    ofile << "<users>" << std::endl;

    std::map<std::string, User *>::iterator it;

    for (it = usersList.begin(); it != usersList.end(); ++it)
    {
        ((it)->second)->dump(ofile);
    }
    ofile << "</users>" << std::endl;
}










