
#include <iostream>
#include <thread>
#include <unistd.h>
#include <list>


namespace ilrd
{
    class Bank
    {
        public:

        Bank() = default;
        ~Bank() = default;

        void AddAccount(std::string name, size_t bank_account, size_t ping_code, double money_amount);
        void RemoveAccount(std::string name, size_t bank_account);
        
        private:

        Bank(const Bank& other) = delete;
        Bank& operator=(const Bank& other) = delete;

        std::list<BankAccount> m_accounts; 

    };
    class BankAccount
    {
        private:
        BankAccount(const BankAccount& other) = delete;
        BankAccount& operator=(const BankAccount& other) = delete;
        
        std::string m_name;
        size_t m_account;
        size_t m_ping_code;
        int m_amount;
        std::thread m_credit_destroyed;
        bool m_credit_status = false;
        size_t m_credit_amount;
        size_t m_credit_percent;
        size_t m_time_left;
        bool m_secret_flag = false;

        public:
    
        BankAccount(std::string name, size_t bank_account, size_t ping_code, double money_amount = 0);
        ~BankAccount();
        void Deposit(size_t amount);
        bool Withdraw(size_t amount);
        double GetBalance() const;
        void DisplayAccountInfo() const;
        void TakeACredit(size_t amount, size_t percent, size_t time);
        void BankAccountDestroyer();
        
    };
    class GenerateAccountData
    {
        public:

        GenerateAccountData();
        ~GenerateAccountData() = default;

        GenerateAccountData(~GenerateAccountData)
    }
}

using namespace ilrd;

BankAccount::BankAccount(std::string name, size_t bank_account, size_t ping_code, double money_amount):m_account(bank_account), m_ping_code(ping_code), m_amount(money_amount), m_credit_amount(0), m_credit_percent(0), m_time_left(0), m_name(name)
{
    m_credit_destroyed = std::thread(&BankAccount::BankAccountDestroyer, this);
}

BankAccount::~BankAccount()
{
    m_credit_destroyed.detach();
}

void BankAccount::Deposit(size_t amount)
{
    m_amount += amount;
    DisplayAccountInfo();
}

bool BankAccount::Withdraw(size_t amount)
{
    if(amount < m_amount)
    {   
        m_amount -= amount;
        std::cout<< "You withdrew " << amount << std::endl;
        return true;
    }
    std::cout<< "You are too poor, try write with one 0 less =)" << std::endl;
    DisplayAccountInfo();
    return false;
}

double BankAccount::GetBalance() const
{
    return m_amount;
}
        
void BankAccount::DisplayAccountInfo() const
{
    std::cout << "Your infomation is:" << std::endl;
    std::cout << "account number is: " << m_account << std::endl;
    std::cout << "account ping code is: " << m_ping_code << std::endl;
    std::cout << "account money amount is: " << m_amount << std::endl;
    std::cout << "account credit amount is: " << m_credit_amount << std::endl;
    std::cout << "account credit percent is: " << m_credit_percent << std::endl;
    std::cout << "account credit time left is: " << m_time_left << std::endl;
}

void BankAccount::TakeACredit(size_t amount, size_t percent, size_t time)
{
    m_credit_amount = amount;
    m_credit_percent = percent;
    m_time_left = time;
    std::cout << "Credit recieved ^^" << std::endl;
    m_credit_status = true;
    DisplayAccountInfo();
}


void BankAccount::BankAccountDestroyer()
{
    while(1)
    {
        if(m_credit_status == false)
        {
            continue;
        }
        else
        {
            if(m_time_left == 0)
            {
                m_credit_status = false;
                std::cout << "Credit payed. You did not get destroyed. Good shit bro." << std::endl;
            }
            else
            {

                std::this_thread::sleep_for(std::chrono::seconds(3));
                std::cout << "Month passed time to pay" << std::endl;
                m_amount -= m_credit_amount * m_credit_percent/100;
                --m_time_left;
                if(m_amount < 0)
                {
                    if(m_secret_flag == false)
                    {
                        m_credit_percent *= 3;
                        m_secret_flag = true;
                        
                    }
                    
                    std::cout << "You have no paying ability. Bank secret percent raised. You have minus so you will get even more minus =)" << std::endl;
                }
                DisplayAccountInfo();
            }
            
        }
    }
}

void Bank::AddAccount(std::string name, size_t bank_account, size_t ping_code, double money_amount)
{

}

void Bank::RemoveAccount(std::string name, size_t bank_account)
{

}

int main()
{

    return 0;
}