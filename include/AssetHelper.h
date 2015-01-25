/*
 * AssetHelper.h
 *
 *  Created on: Jan 24, 2015
 *      Author: justinrempel
 */

#ifndef ASSETHELPER_H_
#define ASSETHELPER_H_

#ifdef _WIN32
const char* ASSET_DIR = "assets/";
#else
const char* ASSET_DIR = "assets/";
#endif

#include <string>

const char* getFullPath(const char* filename) {
	std::string dir = std::string(ASSET_DIR);
	std::string path = dir + filename;

	return path.c_str();
}


#endif /* ASSETHELPER_H_ */
