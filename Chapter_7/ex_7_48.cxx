std::string null_isbn("999-999999-99"); //implicit conversion between C-string and string
Sales_data item1(null_isbn);
Sales_data item2("999-999999-99"); //implicit type conversion when parameter is initialized

//There is no implicit type conversion between class type and other types
//So if the Sales_dat constructors are explicit, these code still works, because they are both direct initialization
