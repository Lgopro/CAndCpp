

#include <iostream>
#include <list>
#include <unordered_map>
#include <utility>


namespace ilrd
{
    class Product
    {
        public:

        Product(std::string name, unsigned int price, unsigned int quantity);
        ~Product() = default;
        
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
        
        
        void Add(Product& product, int amount);
        void Remove(Product& product, int amount);

        private:

        ShopingCart(const ShopingCart& other) = delete;
        ShopingCart& operator=(const ShopingCart& other) = delete;

        std::unordered_map<std::string, std::pair<Product, int>> m_product_list;
    };

}


using namespace ilrd;

Product::Product(std::string name, unsigned int price, unsigned int quantity):m_name(name), m_price(price), m_quantity(quantity)
{

}

void ShopingCart::Add(Product& product, int amount)
{
    
    if(m_product_list.end() == m_product_list.find(product->m_name))
    {
        m_product_list.insert(std::pair<<std::string, std::pair<Product, int>>(product->m_name, std::pair<Product, int>(product, amount)));
    }
    else
    {
        m_product_list[product->m_name].second().second() += amount;
    }

}

void ShopingCart::Remove(Product& product, int amount)
{
    if(m_product_list.end() == m_product_list.find(product->m_name))
    {
        std::cout << "No such product found" << std::endl;
    }
    else
    {
        if(m_product_list[product->m_name].second().second() > amount)
        {
            m_product_list[product->m_name].second().second() -= amount;
        }
        else
        {
            m_product_list.Remove(product->m_name);
        }
        
    }
}