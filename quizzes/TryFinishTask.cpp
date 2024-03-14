
#include <iostream>
#include <list>
#include <unordered_map>
#include <utility>
#include <string>

namespace ilrd
{
    class Product
    {
        public:

        Product(std::string name, unsigned int price, unsigned int quantity);
        ~Product() = default;

        std::string GetName() ;
        unsigned int GetPrice() ;
        unsigned int GetQuantity() ;
        void SetQuantity(unsigned int quantity_to_add);

        private:

        Product(const Product& other) = delete;
        Product& operator=(const Product& other) = delete;

        std::string m_name;
        unsigned int m_price;
        unsigned int m_quantity;

    };

    class ShopingCart
    {
        public:

        ShopingCart() = default;
        ~ShopingCart() = default;
        
        
        void Add(Product& product, unsigned int amount);
        void Remove(Product& product, unsigned int amount);
        void ListAllProducts() const;
        unsigned int CountPrice() const;

        private:

        ShopingCart(const ShopingCart& other) = delete;
        ShopingCart& operator=(const ShopingCart& other) = delete;

        std::unordered_map<std::string, Product> m_product_list;
    };

}


using namespace ilrd;

Product::Product(std::string name, unsigned int price, unsigned int quantity):m_name(name), m_price(price), m_quantity(quantity)
{

}

void ShopingCart::Add(Product& product, unsigned int amount)
{
    Product add(product.GetName(), product.GetPrice(), product.GetQuantity());

    if(m_product_list.end() == m_product_list.find(product.GetName()))
    {
        m_product_list.emplace(product.GetName(), add);
    }
    else
    {
        auto iter = m_product_list.find(product.GetName());
        Product& prod = iter->second;
        prod.SetQuantity(prod.GetQuantity() + amount);
    }
}

void Product::SetQuantity(unsigned int quantity_to_add)
{
    m_quantity = quantity_to_add;
}

std::string Product::GetName() 
{
    return m_name;
}
        
unsigned int Product::GetPrice() 
{
    return m_price;
}
        
unsigned int Product::GetQuantity() 
{
    return m_quantity;
}

void ShopingCart::Remove(Product& product, unsigned int amount)
{

    if(m_product_list.end() == m_product_list.find(product.GetName()))
    {
        std::cout << "No such product found" << std::endl;
    }
    else
    {
        auto iter = m_product_list.find(product.GetName());
        Product& prod = iter->second;
        
        if(prod.GetQuantity() > amount)
        {
            prod.SetQuantity(prod.GetQuantity() - amount);
        }
        else
        {
            m_product_list.erase(iter);
        }
        
    }
}


void ShopingCart::ListAllProducts() const
{

}

unsigned int ShopingCart::CountPrice() const
{
    return 1;
}

int main()
{
    Product pen("pen", 5, 10);
    Product car("Car", 50000, 1);




    return 0;
}