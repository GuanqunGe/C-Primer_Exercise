//It is not legal, because the order of arguments being evaluated at run-time is not guaranteed.

//first, postfix increment has higher precedence than dereference operator, so it's essentially:
iter = vi.insert(iter, *(iter++));
iter += 2;

// two possible cases:
// 1. the left argument being evaluated first. 
// a duplicate element will be added before the odd-valued element, and the program runs in the same way as expected


// 2. the second argument is evaluated first:
// a duplicated element will be added after the odd-valued element found, and with iter being assigned to the return of insert, iter actually points to the newly-added element after the orginal element. In this case, iter += 2 skips unprocessed element after every odd-valued original element.
