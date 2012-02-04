/* */
#include <QtCore/qglobal.h>

void cmakeRequireSymbol(int dummy,...){(void)dummy;}
int main()
{
#ifndef Q_WS_MAC
  cmakeRequireSymbol(0,&Q_WS_MAC);
#endif
  return 0;
}


