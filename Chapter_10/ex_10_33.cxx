#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

int main(int argc, char **argv){

    if(argc < 4){
	std::cerr << "Need 3 argument: file to process, two files to save the output " << std::endl;
	return -1;
    }

    // open files
    std::ifstream infile(argv[1]);
    std::ofstream outodd(argv[2]), outeven(argv[3]);
    if(!infile || !outodd || !outeven){
	std::cerr << "Fail to open (one of) these files" << argv[1] << ", " << argv[2] << ", " << argv[3] << std::endl;
	return -2;
    }

    // define stream_iterator associated with these files
    std::istream_iterator<int> in_iter(infile), in_eof;
    std::ostream_iterator<int> outodd_iter(outodd, " "), outeven_iter(outeven, "\n");

    // method 1
    // use for_each to tranverse through every element
    std::for_each(in_iter, in_eof, [&](int i) { i % 2 ? outodd_iter = i : outeven_iter = i; });
    //std::for_each(in_iter, in_eof, [=](int i) { i % 2 ? outodd_iter = i : outeven_iter = i; });
    // capture by value doens't work for the stream_iterator, as it seems copy operation yield an const stream iterator, which does not allow assignment

    
    //method 2
    //tranverse through every element, and do assignment accordingly
    while( in_iter != in_eof){
	if( *in_iter % 2) //if it's odd
	    outodd_iter = *in_iter;
	else
	    outeven_iter = *in_iter;
	++in_iter;	
    }
    

    infile.close(); outodd.close(); outeven.close();
 
    return 0;
}
