//
//  Product.cpp
//  ms3
//
//  Created by mon sta cruz on 2018-07-23.
//  Copyright © 2018 mon. All rights reserved.
//

#include "Product.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

namespace AMA {
    
    
// PROTECTED FUNCTIONS
    void Product::name(const char * input){
        char * tmp;
        if (input != nullptr){
            tmp = new char[strlen(input) +1];
            strncpy(tmp, input, max_name_length);
        } else {
            tmp = new char[1];
            strcpy(tmp,"\0");
        }
        
        strcpy(pName, tmp);
        delete [] tmp;
        tmp = nullptr;
    }
    
    const char * Product::name() const{
        return pName;
    }
    
    const char * Product::sku() const{
        return pSku;
    }
    
    const char * Product::unit() const{
        return pUnit;
    }
    
    bool Product::taxed() const{
        return pTaxable;
    }
    
    double Product::price() const{
        return pPrice;
    }
    
    double Product::cost() const{
        return pPrice * CURRTAX;
    }
    
    void Product::message(const char * input){
        pErr.message(input);
    }
    
    bool Product::isClear() const{
        return pErr.isClear();
    }
    
// SETTER
    void Product::set(const char * skuInput, const char * nameInput, const char * unitInput, int onHandInput, bool taxInput, double priceInput, int qtyNeededInput){
        strcpy(pSku, skuInput);
        strcpy(pUnit, unitInput);
        strcpy(pName, nameInput);
        pQtyOh = onHandInput;
        pQtyNeeded = qtyNeededInput;
        pPrice = priceInput;
        pTaxable = taxInput;
        pErr.message("");
    }
    
// CONSTRUCTORS
    Product::Product(char type){
        pType = type;
        set("\0", "\0", "\0", 0, true, 0, 0);
        pErr.clear();
    }
    
    Product::Product(const char * sku, const char * name, const char * unit, int onHand, bool taxable, double price, int qtyNeeded){
        pType = 'N';
        set(sku, name, unit, onHand, taxable, price, qtyNeeded);
        pErr.message("");
    }
    
    Product::Product(const Product & input){
        pType = input.pType;
        set(input.pSku, input.pName, input.pUnit, input.pQtyOh, input.pTaxable, input.pPrice, input.pQtyNeeded);
        pErr.message(input.pErr.message());
    }
    
// OPERATORS
    void Product::operator = (const Product & input){
        pType = input.pType;
        set(input.pSku, input.pName, input.pUnit, input.pQtyOh, input.pTaxable, input.pPrice, input.pQtyNeeded);
        pErr.message(input.pErr.message());
    }
    
    bool Product::operator==(const char * input) const{
        bool result = false;
        if(strcmp(pSku, input) == 0)
            result = true;
        return result;
    }
    
    bool Product::operator > (const char * input) const{
        bool result = false;
        if (strcmp(pSku, input) > 0)
            return result;
        return result;
    }
    
    bool Product::operator > (const iProduct & input) const{
        bool result = false;
        if (strcmp(name(), input.name()) > 0)
            result = true;
        return result;
    }
    
    int Product::operator+=(int input){
        if(input > 0){
            pQtyOh += input;
        }
        return pQtyOh;
    }
    
// FSTREAM FUNCTIONS
    fstream& Product::store(fstream& file, bool newline) const{
        char comma = ',';
        if (file.is_open()){
            file << pType << comma
            << pSku << comma
            << pName << comma
            << pUnit << comma
            << (pTaxable ? 1 : 0) << comma
            << cost() << comma
            << pQtyOh << comma
            << pQtyNeeded;
            
            if(newline)
                file << endl;
        }
        return file;
    }
    
    fstream& Product::load(fstream& file){
        Product tmp;
        char comma;
        if (file.is_open()){
            double cost;
            file >> tmp.pType >> comma
            >> tmp.pSku >> comma
            >> tmp.pName >> comma
            >> cost >> comma
            >> tmp.pQtyOh >> comma
            >> tmp.pQtyNeeded >> comma;
            
            tmp.pPrice = cost/CURRTAX;
            cout << "HEHE XD" << endl;
            *this = tmp;
            cout << "HEHE D:" << endl;
        }
        return file;
    }

// OSTREAM & ISTREAM
    ostream& Product::write(ostream& os, bool linear) const{
        if (isClear()){
            if (linear){
                char bracket = '|';
                os << setw(max_sku_length) << left <<pSku << bracket;
                os << setw(20) << left << pName << bracket;
                os << setw(7) << fixed << setprecision(2) << right << (pTaxable? cost() : (cost() / CURRTAX)) << bracket;
                os << setw(4) << pQtyOh << bracket;
                os << setw(10) << left << pUnit << bracket;
                os << setw(4) << right << pQtyNeeded << bracket;
            } else {
                os << " Sku: " << pSku << endl
                << " Name (no spaces): " << pName << endl
                << " Price: " << pPrice << endl
                << " Price after tax: " << cost() << endl
                << " Quantity on hand: " << pQtyOh << endl
                << " Quantity needed: " << pQtyNeeded << endl;
            }
        }
        else
            os << pErr.message();
        return os;
    }
    
    istream& Product::read(istream& is){
        char tax;
        bool valid = true;
        cout << " Sku: ";
        is >> pSku;
        cout << " Name (no spaces): ";
        is >> pName;
        cout << " Unit: ";
        is >> pUnit;
        cout << " Taxed? (y/n): ";
        is >> tax;
        if (tax != 'y' && tax != 'Y' && tax != 'n' && tax != 'N'){
            is.setstate(ios::failbit);
            valid = false;
            message("only (Y)es or (N)o are acceptable");
        }
        if (valid){
        cout << " Price: ";
        is >> pPrice;
            if(is.fail()){
                message("Invalid Price Entry");
                valid = false;
            }
        }
        if (valid){
        cout << " Quantity on hand: ";
        is >> pQtyOh;
            if (is.fail()){
                message("Invalid Quantity Entry");
                valid = false;
            }
        }
        if (valid){
        cout << " Quantity needed: ";
        is >> pQtyNeeded;
            if (is.fail()){
                message("Invalid Quantity Needed Entry");
                valid = false;
            }
        }
       // if (is.fail())
       //     cout << pErr.message();
        if (tax == 'y' || tax == 'Y')
            pTaxable = true;
        else
            pTaxable = false;
        return is;
    }
    
    ostream& operator << (ostream& os , const iProduct& input){
        input.write(os, true);
        return os;
    }
    
    istream& operator >>(istream& is, iProduct& input){
        input.read(is);
        return is;
    }
    
// OTHER MEMBER FUNCTIONS
    double Product::total_cost() const{
        return cost() * pQtyOh;
    }
    
    void Product::quantity(int input){
        pQtyOh = input;
    }
    
    bool Product::isEmpty() const{
        bool result = false;
        if (strcmp(pSku, "\0") == 0)
            result = true;
        return result;
    }
    
    int Product::qtyNeeded() const{
        return pQtyNeeded;
    }
    
    int Product::quantity() const{
        return pQtyOh;
    }
    
// DESTRUCTOR
    Product::~Product(){
        pErr.clear();
    }
    
// HELPER FUNCTIONS
    double operator +=(double & doubleInput, const iProduct& prodInput){
        return doubleInput + prodInput.total_cost();
    }
}
