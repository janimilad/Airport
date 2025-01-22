#include <iostream>
#include <conio.h>

#define ANSI_RESET "\x1B[0m"
#define ANSI_YELLOW "\x1B[33m"
#define ANSI_RED "\x1B[31m"
#define ANSI_BLUE "\x1B[34m"
#define ANSI_GREEN "\x1B[32m"
#define ANSI_CYAN "\x1B[36m"
#define ANSI_BOLD "\x1B[1m"

using namespace std;

void cls() { system("cls"); }

// Class: Date
class Date
{
private:
  int day;
  int month;
  int year;
  int hour;
  int minute;

public:
  Date()
  {
    day = 0;
    month = 0;
    year = 0;
    hour = 0;
    minute = 0;
  }
  void setDay(int d) { day = d; }
  int getDay() { return day; }

  void setMonth(int m) { month = m; }
  int getMonth() { return month; }

  void setYear(int y) { year = y; }
  int getYear() { return year; }

  void setHour(int h) { hour = h; }
  int getHour() { return hour; }

  void setMinute(int m) { minute = m; }
  int getMinute() { return minute; }

  friend ostream &operator<<(ostream &out, Date &date);
  friend istream &operator>>(istream &in, Date &date);
};
ostream &operator<<(ostream &out, Date &date)
{
  out << date.getDay() << "/" << date.getMonth() << "/" << date.getYear()
      << " " << date.getHour() << ":" << date.getMinute();
  return out;
}
istream &operator>>(istream &in, Date &date)
{
  in >> date.day >> date.month >> date.year >> date.hour >> date.minute;
  return in;
}

// Class: Food
class Food
{
private:
  string type;
  string meal;

public:
  Food()
  {
    type = "-";
    meal = "-";
  }
  void setType(string &t) { type = t; }
  string getType() { return type; }

  void setMeal(string &m) { meal = m; }
  string getMeal() { return meal; }

  friend ostream &operator<<(ostream &out, Food &food);
  friend istream &operator>>(istream &in, Food &food);
};
ostream &operator<<(ostream &out, Food &food)
{
  out << "Meal Type: " << food.getType() << " ,Meal name: " << food.getMeal();
  return out;
}
istream &operator>>(istream &in, Food &food)
{
  in >> food.type >> food.meal;
  return in;
}

// Class: Airport
class Airport
{
protected:
  string domesticFlights[10];
  string foreignFlights[10];

public:
  virtual void addFlight(string &flight) = 0;
  virtual void removeFlight(string &flight) = 0;
  virtual void displayFlights() = 0;
};

// Class: DomesticFlights (Derived from Airport)
class DomesticFlights : public Airport
{
private:
  string originCity;
  string destinationCity;
  Date flightDate;
  string planeName;
  bool isCancelled;
  Food food;

public:
  DomesticFlights()
  {
    originCity = "-";
    destinationCity = "-";
    planeName = "-";
    isCancelled = 0;
  }

  void setOriginCity(string &city) { originCity = city; }
  string getOriginCity() { return originCity; }

  void setDestinationCity(string &city) { destinationCity = city; }
  string getDestinationCity() { return destinationCity; }

  void setFlightDate(Date &date) { flightDate = date; }
  Date getFlightDate() { return flightDate; }

  void setPlaneName(string &name) { planeName = name; }
  string getPlaneName() { return planeName; }

  void setIsCancelled(bool cancelled) { isCancelled = cancelled; }
  bool getIsCancelled() { return isCancelled; }

  void setFood(Food &f) { food = f; }
  Food getFood() { return food; }

  void addFlight(string &flight) override
  {
    for (int i = 0; i < 10; ++i)
    {
      if (domesticFlights[i].empty())
      {
        domesticFlights[i] = flight;
        break;
      }
    }
  }

  void removeFlight(string &flight) override
  {
    for (int i = 0; i < 10; ++i)
    {
      if (domesticFlights[i] == flight)
      {
        domesticFlights[i].clear();
        break;
      }
    }
  }

  void displayFlights() override
  {
    cout << ANSI_YELLOW << "Domestic Flights: " << endl;
    for (int i = 0; i < 10; ++i)
    {
      if (!domesticFlights[i].empty())
      {
        cout << domesticFlights[i] << endl;
      }
    }
  }
  void displayFlightInformatoin()
  {
    cout << "Domestic Flight Information: \n";
    cout << "Origincity: " << originCity << endl;
    cout << "Destinationcity: " << destinationCity << endl;
    cout << "Flight date: " << flightDate << endl;
    cout << "Plane name: " << planeName << endl;
    cout << "Food: " << food << endl;
    cout << "Is cancelled: " << isCancelled << ANSI_RESET << endl;
  }
};

// Class: DomesticCities
class DomesticCities
{
private:
  string cities[10];

public:
  void addCity(string &city)
  {
    for (int i = 0; i < 10; ++i)
    {
      if (cities[i].empty())
      {
        cities[i] = city;
        break;
      }
    }
  }

  string getCities()
  {
    string allCities;
    for (int i = 0; i < 10; ++i)
    {
      if (!cities[i].empty())
      {
        allCities += cities[i] + ", ";
      }
    }
    return allCities;
  }
};

// Class: ForeignFlights (Derived from Airport)
class ForeignFlights : public Airport
{
private:
  string originCity;
  string destinationCity;
  Date flightDate;
  string planeName;
  bool isCancelled;
  Food food;

public:
  ForeignFlights()
  {
    originCity = "-";
    destinationCity = "-";
    planeName = "-";
    isCancelled = 0;
  }
  void setOriginCity(string &city) { originCity = city; }
  string getOriginCity() { return originCity; }

  void setDestinationCity(string &city) { destinationCity = city; }
  string getDestinationCity() { return destinationCity; }

  void setFlightDate(Date &date) { flightDate = date; }
  Date getFlightDate() { return flightDate; }

  void setPlaneName(string &name) { planeName = name; }
  string getPlaneName() { return planeName; }

  void setIsCancelled(bool cancelled) { isCancelled = cancelled; }
  bool getIsCancelled() { return isCancelled; }

  void setFood(Food &f) { food = f; }
  Food getFood() { return food; }

  void addFlight(string &flight) override
  {
    for (int i = 0; i < 10; ++i)
    {
      if (foreignFlights[i].empty())
      {
        foreignFlights[i] = flight;
        break;
      }
    }
  }

  void removeFlight(string &flight) override
  {
    for (int i = 0; i < 10; ++i)
    {
      if (foreignFlights[i] == flight)
      {
        foreignFlights[i].clear();
        break;
      }
    }
  }

  void displayFlights() override
  {
    cout << ANSI_YELLOW << "Foreign Flights: " << endl;
    for (int i = 0; i < 10; ++i)
    {
      if (!foreignFlights[i].empty())
      {
        cout << foreignFlights[i] << endl;
      }
    }
  }
  void displayFlightInformatoin()
  {
    cout << "Foreighn Flight Information: \n";
    cout << "OOrigincity: " << originCity << endl;
    cout << "Destinationcity: " << destinationCity << endl;
    cout << "Flight date: " << flightDate << endl;
    cout << "Plane name: " << planeName << endl;
    cout << "Food: " << food << endl;
    cout << "Is cancelled: " << isCancelled << ANSI_RESET << endl;
  }
};

// Class: ForeignCities
class ForeignCities
{
private:
  string cities[10];

public:
  void addCity(string &city)
  {
    for (int i = 0; i < 10; ++i)
    {
      if (cities[i].empty())
      {
        cities[i] = city;
        break;
      }
    }
  }

  string getCities()
  {
    string allCities;
    for (int i = 0; i < 10; ++i)
    {
      if (!cities[i].empty())
      {
        allCities += cities[i] + ", ";
      }
    }
    return allCities;
  }
};

// Class: Customer
class Customer
{
private:
  string name;
  double balance;
  string purchasedFlights[10];

public:
  void setName(string n) { name = n; }
  string getName() { return name; }

  void setBalance(double b) { balance = b; }
  double getBalance() { return balance; }

  void addPurchasedFlight(string &flight)
  {
    for (int i = 0; i < 10; ++i)
    {
      if (purchasedFlights[i].empty())
      {
        purchasedFlights[i] = flight;
        break;
      }
    }
  }

  string getPurchasedFlights()
  {
    string history;
    for (int i = 0; i < 10; ++i)
    {
      if (!purchasedFlights[i].empty())
      {
        history += purchasedFlights[i] + ", ";
      }
    }
    return history;
  }

  void refundTicket(string &flight)
  {
    for (int i = 0; i < 10; ++i)
    {
      if (purchasedFlights[i] == flight)
      {
        purchasedFlights[i].clear();
        cout << "Ticket refunded successfully." << endl;
        break;
      }
    }
  }
};

// Class: Admin
class Admin
{
private:
  string adminName;
  string adminPassword;

public:
  void setAdminName(string name) { adminName = name; }
  string getAdminName() { return adminName; }

  void setAdminPassword(string password) { adminPassword = password; }
  string getAdminPassword() { return adminPassword; }

  bool authenticate(string &name, string &password)
  {
    return name == adminName && password == adminPassword;
  }
  void manageFlights(ForeignFlights &F, DomesticFlights &D)
  {
    int choice;
    cls();
    cout << ANSI_BLUE << ANSI_BOLD << "======================" << endl;
    cout << "Admin - Manage Flights" << endl;
    cout << "======================" << ANSI_RESET << endl;
    cout << ANSI_CYAN << "1. Add Flight" << endl;
    cout << "2. Remove flight" << endl;
    cout << "3. Change flight information" << endl;
    cout << "4. Show all flights" << endl;
    cout << "5. Exit" << endl;
    cout << ANSI_YELLOW << "Choose an option: " << ANSI_RESET;
    cin >> choice;
    cin.ignore();

    switch (choice)
    {

    case 1:
      char ftype;
      cout << ANSI_YELLOW << "Enter flight type D/F: ";
      cin >> ftype;
      if (ftype == 'D' || ftype == 'd')
      {
        cout << "Enter domestic flight name:" << ANSI_RESET;
        string f;
        cin >> f;
        D.addFlight(f);
        cout << ANSI_GREEN << "Flight added successfully." << ANSI_RESET << endl;
        getch();
      }
      else if (ftype == 'F' || ftype == 'f')
      {
        cout << ANSI_YELLOW << "Enter forign flight name:" << ANSI_RESET;
        string f;
        cin >> f;
        F.addFlight(f);
        cout << ANSI_GREEN << "Flight added successfully." << ANSI_RESET << endl;
        getch();
      }
      else
      {
        cout << ANSI_RED << "Invalid input !\n"
             << ANSI_RESET;
        cin.clear();
        cin.ignore();
        getch();
      }
      break;
    case 2:
    {
      char ftype;
      cout << ANSI_YELLOW << "Enter flight type D/F: ";
      cin >> ftype;
      if (ftype == 'D' || ftype == 'd')
      {
        cout << "Enter domestic flight name:" << ANSI_RESET;
        string f;
        cin >> f;
        D.removeFlight(f);
        cout << ANSI_RED << "Flight removed successfully." << ANSI_RESET << endl;
        getch();
      }
      else if (ftype == 'F' || ftype == 'f')
      {
        cout << ANSI_YELLOW << "Enter forign flight name:" << ANSI_RESET;
        string f;
        cin >> f;
        F.removeFlight(f);
        cout << ANSI_RED << "Flight removed successfully." << ANSI_RESET << endl;
        getch();
      }
      else
      {
        cout << ANSI_RED << "Invalid input !\n"
             << ANSI_RESET;
        getch();
      }

      break;
    }
    case 3:
    {
      char ftype;
      cout << ANSI_YELLOW << "Enter flight type D/F: ";
      cin >> ftype;
      if (ftype == 'D' || ftype == 'd')
      {
        string fname;
        cout << "Enter flight name: ";
        cin >> fname;
        D.addFlight(fname);
        //
        string Flightdestination;
        cout << "Enter Flight destination: ";
        cin >> Flightdestination;
        D.setDestinationCity(Flightdestination);
        //
        string Origincity;
        cout << "Enter Flight origincity: ";
        cin >> Origincity;
        D.setOriginCity(Origincity);
        //
        Food food;
        string meal;
        string type;
        cout << "Enter food meal: ";
        cin >> meal;
        cout << "Enter food type: ";
        cin >> type;
        food.setMeal(meal);
        food.setType(type);
        D.setFood(food);
        //
        string planename;
        cout << "Enter Plane name: ";
        cin >> planename;
        D.setPlaneName(planename);
        //
        Date date;
        int day;
        int month;
        int year;
        int hour;
        int minute;
        cout << "Enter flight year: ";
        cin >> year;
        cout << "Enter flight month: ";
        cin >> month;
        cout << "Enter flight day: ";
        cin >> day;
        cout << "Enter flight hour: ";
        cin >> hour;
        cout << "Enter flight minute: " << ANSI_RESET;
        cin >> minute;
        date.setYear(year);
        date.setMonth(month);
        date.setDay(day);
        date.setHour(hour);
        date.setMinute(minute);
        D.setFlightDate(date);
        cout << ANSI_GREEN << "Flight info changed sucsessflly !\n"
             << ANSI_RESET;
        getch();
      }
      //
      else if (ftype == 'F' || ftype == 'f')
      {
        string fname;
        cout << "Enter flight name: ";
        cin >> fname;
        D.addFlight(fname);
        //
        string Flightdestination;
        cout << "Enter Flight destination: ";
        cin >> Flightdestination;
        D.setDestinationCity(Flightdestination);
        //
        string Origincity;
        cout << "Enter Flight origincity: ";
        cin >> Origincity;
        D.setOriginCity(Origincity);
        //
        Food food;
        string meal;
        string type;
        cout << "Enter food meal: ";
        cin >> meal;
        cout << "Enter food type: ";
        cin >> type;
        food.setMeal(meal);
        food.setType(type);
        D.setFood(food);
        //
        string planename;
        cout << "Enter Plane name: ";
        cin >> planename;
        D.setPlaneName(planename);
        //
        Date date;
        int day;
        int month;
        int year;
        int hour;
        int minute;
        cout << "Enter flight year: ";
        cin >> year;
        cout << "Enter flight month: ";
        cin >> month;
        cout << "Enter flight day: ";
        cin >> day;
        cout << "Enter flight hour: ";
        cin >> hour;
        cout << "Enter flight minute: " << ANSI_RESET;
        cin >> minute;
        date.setYear(year);
        date.setMonth(month);
        date.setDay(day);
        date.setHour(hour);
        date.setMinute(minute);
        D.setFlightDate(date);
        cout << ANSI_GREEN << "Flight info changed sucsessflly !\n"
             << ANSI_RESET;
        getch();
      }
      break;
    }

    case 4:
      F.displayFlights();
      cout << ANSI_BOLD << "-----------------\n"
           << ANSI_RESET;
      D.displayFlights();
      getch();
      break;

    case 5:
      cls();
      return;
    default:
      cout << ANSI_RED << "Invalid choice. Please try again!" << ANSI_RESET << endl;
      cin.clear();
      cin.ignore();
      break;
    }

    manageFlights(F, D);
  }
};

// Class: Tax
class Tax
{
public:
  double calculateTax(double price, double percentage)
  {
    return price * (percentage / 100);
  }
};

void adminMenu(Admin &admin, ForeignFlights &F, DomesticFlights &D)
{
  cls();

  admin.manageFlights(F, D);
}

void customerMenu(Customer &customer, ForeignFlights &F, DomesticFlights &D)
{
  int choice;
  cls();
  cout << ANSI_BOLD << ANSI_BLUE << "=============" << endl;
  cout << "Customer Menu" << endl;
  cout << "=============" << ANSI_RESET << endl;
  cout << ANSI_CYAN << "1. Add Balance" << endl;
  cout << "2. Add Flight" << endl;
  cout << "3. View Purchased Flights" << endl;
  cout << "4. Refund Ticket" << endl;
  cout << "5. View All Flights" << endl;
  cout << "6. Exit" << ANSI_RESET << endl;
  cout << ANSI_YELLOW << "Choose an option: ";
  cin >> choice;
  cin.ignore();

  switch (choice)
  {
  case 1:
  {
    double amount;
    cout << "Enter amount to add: ";
    cin >> amount;
    customer.setBalance(amount);
    break;
  }
  case 2:
  {
    string flight;
    cout << "Enter flight name:";
    cin >> flight;
    customer.addPurchasedFlight(flight);
    getch();
    break;
  }
  case 3:
    cout << "Purchased Flights: " << customer.getPurchasedFlights() << endl;
    getch();
    break;
  case 4:
  {
    string flight;
    cout << "Enter flight to refund: " << ANSI_RESET;
    getline(cin, flight);
    customer.refundTicket(flight);
    break;
  }
  case 5:
  {
    cls();
    D.displayFlights();
    D.displayFlightInformatoin();
    cout << "----------------------\n";
    F.displayFlights();
    F.displayFlightInformatoin();
    getch();
    break;
  }
  case 6:
    cls();
    return;
  default:
    cout << ANSI_RED << "Invalid choice. Try again!" << ANSI_RESET << endl;
    break;
  }
  customerMenu(customer, F, D);
}

void menu(Admin &admin, Customer &customer, ForeignFlights &F, DomesticFlights &D)
{
  int userType;
  cls();
  cout << ANSI_BLUE << ANSI_BOLD << "==============================" << endl;
  cout << "Welcome to the Airport System!" << endl;
  cout << "==============================" << ANSI_RESET << endl;
  cout << ANSI_CYAN << "1. Admin\n2. Customer\n3. Exit\n";
  cout << ANSI_YELLOW << "Choose user type: " << ANSI_RESET;
  cin >> userType;

  if (userType == 1)
  {
    string adminpass;
    string adminname;
    cout << ANSI_YELLOW << "Enter admin name: ";
    cin >> adminname;
    cout << "Enter admin password: " << ANSI_RESET;
    cin >> adminpass;
    if (admin.getAdminName() == adminname && admin.getAdminPassword() == adminpass)
    {
      adminMenu(admin, F, D);
    }
    else
    {
      cls();
      cout << ANSI_RED "Invalid name or password ! \n"
           << ANSI_RESET;
      getch();
      menu(admin, customer, F, D);
    }
  }
  else if (userType == 2)
  {
    customerMenu(customer, F, D);
  }
  else if (userType == 3)
  {
    exit(0);
  }
  menu(admin, customer, F, D);
}

int main()
{
  cls();
  Admin admin;
  admin.setAdminName("admin");
  admin.setAdminPassword("1234");

  DomesticFlights D;
  ForeignFlights F;

  Customer customer;
  menu(admin, customer, F, D);

  return 0;
}
