#pragma once
#include "CoreMinimal.h"
#include <sstream>

/** For Example */
// LStream Stream;
// std::cout.rdbuf(&Stream);
// std::cout << "some message" << std::endl;#pragma once

class LStream : public std::stringbuf {
protected:
	int sync() {
		UE_LOG(LogTemp, Warning, TEXT("%s\n"), *FString(str().c_str()));
		str("");
		return std::stringbuf::sync();
	}
};

