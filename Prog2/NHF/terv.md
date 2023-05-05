# MVM
**<h1 align="center">Házi Feladat </h1>**

<h2 align = "center">Terv</h2>
<h2 align = "center">Jajecnik Marcell- DMB3AD</h3>
<h2 align = "center">2023. 05. 03.</h2>

# A program struktúrája

*A program osztálydiagramja, a fontosabb adattagokkal és függvényekkel*

```plantuml
@startuml
'  !theme black-knight
!theme crt-amber

MyVektor -- MVM::clients
Client -- MVM::clients
class "MVM" as MVM {
    - MyVektor<Client*> clients - tárolja az ügyfelek adatait
    - static Company adatok - az MVM adatai a számla kiállításához, mivel nem változik így statikus

    + void addContract() - hozzáad egy szerződést
    + void addClient() - hozzáad egy ügyfelet
    + Client* getClient() - Kikeresi a meglévő ügyfelek közül a keresettet
    + ~MVM()
}

MyVektor -- Client::mycontracts
Contract -- Client::mycontracts
class "Client" as Client{
    - std::string name - a ügyfél neve
    - MyVector<Contract *> mycontracts - az ügyfélhez tartozó szerződések
    + Client() - alapértékes konstruktor
    + addContract() - szerződést ad hozzá
    + virtual ~Client() - virtuális destruktor
}

Person <|-Client
class "Person" as Person{
    - long ID - személyazonosító szám
    + void getID() const - visszaadja a személyazonosító számot
    + void setID() - beállítja a személyazonosító számot
}

Company <|-Client
class "Company" as Company{
    - long Tax_ID - adóazonosító szám
    + void getID() const - visszaadja az adóazonosító számot
    + void setID() - beállítja az adóazonosító számot
}

Client -- Contract::client
ContractType -- Contract::contract_type
Contract_date -- Contract::contract_time
class "Contract" as Contract {
    - Client& client - ügyfél adatai
    - ContractType contract_type - szerződés típusa
    - Contract_date contract_time - szerződés itőtartama eleje és vég megadásával
    - time_t last_invoicing - legutóbbi számlázás ideje
    - double tariff - kilowattóránkénti ár forintban megadva
    - double balance - jelenlegi egyenleg
    - double consumption - fogyasztás a legutóbbi számlázás óta
    + Client() - Alapértékes konstruktor
    + Client getClient() const - visszaad egy Client-et ami tartalmazza a szerződéskötő adatait
    + ClientType getCtype() - visszaadja a szerződés típusát
    + double getTariff() - visszaadja a tarifát ami megadja a KWh óránkénti árat
    + double getBalance() - visszaadja a jelenlegi egyenleget
    + double getConsumption() - visszaadja a jelenlegi fogyasztást a legutóbbi számlázás óta
    + void getCtime() - visszaadja a szerződés hosszát
    + void addConsumption(double con_in) - növeli a fogyasztás értékét a legutóbbi számlázás óta
    + void setCtype() - beállítja a szerződés típusát
    + void setTariff() - beállítja a tarifát ami megadja a KWh óránkénti árat
    + void setBalance() - beállítja a jelenlegi egyenleget
    + void setCtime() - beállítja a szerződés hosszát
    + void setLast_invoicing() - beálllítja a legutóbbi számlázás idejét
    + void pay() - befizetés
    + invoicing() - számla készítése a legutóbbi számlakiállítás óta
    + ~Client() - destruktor
}

enum "ContractType" as ContractType {}

class "Contract_date" as Contract_date {
    - time_t begin - szerződés kezdete
    - time_t end - szerződés vége

    + time_t getBegin() - visszaadja a szerződés kezdetét
    + time_t getEnd() - visszaadja a szerződés végét
    + void setBegin() - beállítja a szerződés kezdetét
    + void setEnd() - beállítja a szerződés végét
    + bool contains() - eldönti hogy a kapott dátum benne van-e a szerződés időtartamában
}

class "MyVektor<T>" as MyVektor {
    - T* m_buffer
    - size_t m_capacity - maximális szám ami még belefér a foglalt memóriába
    - size_t m_size - jelenleg tárolt adatok száma
    - void reserve() - helyet foglal - privát függvény

    + MyVektor() - alapértékes konstruktor
    + void push_back() - belerak egy új adatot ha még nincs tele, ha tele van újat foglal
    + T* begin() - iterátor a tömb elejére
    + T* end() - iterátor a tömb végére
    + size_t size() - visszaadja a jelenleg tárolt adatok számát
    + size_t capacity() - visszaadja a jelenleg foglalt méretet
    + void erase() - kitöröl egy tárolt adatot egy bizonyos helyről
    + void pop_back() - kitörli a legutóbbi elemet
    + ~MyVektor() - destruktor


}
    
@enduml
```

- A person és a company osztályok publikus módon öröklődnek a client-ből
- A myvektor generikus osztály az indexelhetőséghez
- A myvektor amennyiben betelik az eddigi méretének dupláját foglalja
- Egy emberhez több szerződés is kapcsolódhat