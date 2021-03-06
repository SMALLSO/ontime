#include "stdafx.h"
#include <time.h>
#include "ontime.h"

int main()
{
	time_t tInternetUtcTimecut = GetInternetUtcTimecut();
	if (tInternetUtcTimecut != INVALID_TIMECUT)
	{
		SYSTEMTIME obSystemTime = { NULL };
		if (TimecutToSystemTime(tInternetUtcTimecut, &obSystemTime, FALSE))
		{
			if (SetSystemTime(&obSystemTime))
				printf("The system time was successfully synchronized with the SMALLSO Time Server.\n");
			else
				printf("Error: Setting system time failed, error code: %d\n", GetLastError());
		}
		else printf("Error: UTC time intercept returned by SMALLSO Time Server is invalid\n");
	}
	else printf("Error: Unable to connect to SMALLSO Time Server, please try again later.\n");
	system("pause");
    return 0;
}
