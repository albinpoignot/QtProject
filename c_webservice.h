#ifndef C_WEBSERVICE_H
#define C_WEBSERVICE_H

#include <QNetworkAccessManager>

class C_webservice
{
public:
    C_webservice();
    void connect(float lat,float lon);
};

#endif // C_WEBSERVICE_H
