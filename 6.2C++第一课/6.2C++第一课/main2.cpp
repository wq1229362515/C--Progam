#include"iostream"
#include"Test2.h"
using namespace  std;
#if 0
using namespace N1;

namespace N2 {
	int  a ;

}
using namespace N2;

#endif



int  main(){
	Date exap;
	exap.SetDate(2019, 6, 14);
	exap.PrintDate();
	return 0;
}