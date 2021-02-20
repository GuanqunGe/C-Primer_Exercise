Since we did not define copy constructor, copy-assignment operator, and destructor,
the compiler synthesizes these functions for us, each of which copy, copy-assign, destroy 
every non-static member of the class repsectively.

So when we copy/copy-assign the TextQuery or QueryResult classes, string member will be 
copied/copy-assigned using string class' copy constructor, map member will be 
copied/copy-assigned using map class' copy constructor, each object in the map container 
will be copied. shared_ptr member will be copied/copy-assigned using shared_ptr class' 
copy constructor, the use count of corresponding object bound to the right-hand object 
will increase by 1. 

When we destroy the TextQuery or QueryResult class, string member will be destroyed using 
its own destructor, map member will be destroyed using map class' destructor and every 
object in the map container will be destroyed. shared_ptr will be destroyed using its 
own destructor too, and if the use count of the object shared_ptr is bound to reduce to 
0, this object will be destroyed too and memory will be freed.
