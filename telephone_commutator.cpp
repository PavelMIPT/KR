#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

class Country 
{
    protected:
        std::string country;
        std::string id;
    public:

        void index_cin(){
            std::cout << "введите телефонный индекс вашей страны: ";
            std::string index;
            id = index;
            std::cin >> index;

        }
};

// пока нет проверки на то нет ли какого-нибудь номера с другим индексом в телевонной базе в данной стране
class telephone_base : public Country
{
    private:
        // каждый пользователь имеет уникальный номер - ключ, а сообщение - это значение 
        std::map<std::string, std::vector<std::string>> base;
        std::vector<std::string> abonents; 
        std::string name;
    public:
        
        void buildAbonent(){
                std::cout << "< Введите номер абонента: ";
                std::string Abonent;
                std::cin >> Abonent;
                abonents.push_back(Abonent);
        }

        void send_message(std::string number, std::string message){
            // если пользователь найден в базе
            if (std::find(abonents.begin(), abonents.end(), number) != abonents.end())
            {
                std::cout << "< ok";
            }
            else
            {
                std::cout << "< not found";
            }
            base[number].push_back(message);
            std::cout << std::endl;
        }


        void read(std::string number){
            if (std::find(abonents.begin(), abonents.end(), number) != abonents.end())
            {
                std::cout << "< "<< base[number][0];
                base[number].erase(base[number].begin());
                std::cout << std::endl;

            }
            else
            {
                std::cout << "< not found";
            }
        }

        // in - номер перенаправления
        void redirect(std::string in, std::string out)
        {
            if (std::find(abonents.begin(), abonents.end(), out) != abonents.end())
            {
                base[in] = base[out];
            }
            else
            {
                std::cout << "< not found";
            }
        }


};


int main(){
    /*
    Country c ;
    c.index_cin();
    */

    telephone_base A;
    A.buildAbonent();
    A.send_message("79160000000", "hello");
    A.send_message("79160000000", "by");
    A.read("79160000000");
    A.read("79160000000");
    A.redirect("79161000000", "79160000000");
    // A.read("79160000000");  // segmentation fault, we have not a 3 messages

    return 0;
}