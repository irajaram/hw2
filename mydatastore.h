#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include "datastore.h"
#include <vector>
#include <map>
#include <queue>
class MyDataStore :public DataStore{
public:
    MyDataStore();
    ~MyDataStore();

    /**
     * Adds a product to the data store
     */
    void addProduct(Product* p);

    /**
     * Adds a user to the data store
     */
    void addUser(User* u);

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
    std::vector<Product*> search(std::vector<std::string>& terms, int type);

    /**
     * Reproduce the database file from the current Products and User values
     */

    void dump(std::ostream& ofile);
    void addtoCart(const std::string& username,Product* prod);
    void viewCart(const std::string& username);
    void buyCart(const std::string& username);
private:
    std::map<std::string, std::set<Product*>> fullProd;
    std::map<std::string, User*> usersList;
    std::map<std::string, Product*> productsList;
    //std::vector<Product*> Prods;
    //std::vector<User*> Users;
    std::map<std::string,std::queue<Product*>> prodCart;
};
 
#endif
