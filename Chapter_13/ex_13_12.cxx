bool fcn(const Sales_data *trans, Sales_data accum)
//copy initialization of Sales_data object 'accum', and pointer 'trans'
{
 
    Sales_data item1(*trans), item2(accum);
    //copy initialization of two Sales_data object, 'item1', 'item2' 
   return item1.isbn() != item2.isbn();
}
//end of the call, destruction of 4 objects, of which 3 are Sales_data objects, 1 is ordinary pointer
//to destruct the Sales_data object, destructor of its string member is also called.
//so in total there are 6 destructors called.
