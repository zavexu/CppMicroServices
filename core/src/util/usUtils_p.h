/*=============================================================================

  Library: CppMicroServices

  Copyright (c) The CppMicroServices developers. See the COPYRIGHT
  file at the top-level directory of this distribution and at
  https://github.com/saschazelzer/CppMicroServices/COPYRIGHT .

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=============================================================================*/


#ifndef USUTILS_H
#define USUTILS_H

#include <usCoreConfig.h>

#include <string>
#include <vector>
#include <memory>

//-------------------------------------------------------------------
// File system functions
//-------------------------------------------------------------------

namespace us {

const char DIR_SEP_WIN32 = '\\';
const char DIR_SEP_POSIX = '/';

#ifdef US_PLATFORM_WINDOWS
const char DIR_SEP = DIR_SEP_WIN32;
#else
const char DIR_SEP = DIR_SEP_POSIX;
#endif

namespace fs {

// Platform agnostic way to get the current working directory.
// Supports Linux, Mac, and Windows.
std::string GetCurrentWorkingDirectory();
bool not_found_error(int errval);
bool Exists(const std::string& path);

bool IsDirectory(const std::string& path);
bool IsFile(const std::string& path);
bool IsRelative(const std::string& path);

std::string GetAbsolute(const std::string& path);

void MakePath(const std::string& path);

US_Core_EXPORT void RemoveDirectoryRecursive(const std::string& path);

}

}

//-------------------------------------------------------------------
// Bundle name and location parsing
//-------------------------------------------------------------------

namespace us {

std::string GetBundleNameFromLocation(const std::string& location);

std::string GetBundleLocation(const std::string& location);

bool IsSharedLibrary(const std::string& location);

}

//-------------------------------------------------------------------
// Framework storage
//-------------------------------------------------------------------

namespace us {

class CoreBundleContext;

extern const std::string FWDIR_DEFAULT;

std::string GetFrameworkDir(CoreBundleContext* ctx);

/**
 * Check for local file storage directory.
 *
 * @return A directory path or an empty string if no storage is available.
 */
std::string GetFileStorage(CoreBundleContext* ctx, const std::string& name, bool create = true);

}

//-------------------------------------------------------------------
// Bundle auto-loading
//-------------------------------------------------------------------

namespace us {

struct BundleInfo;
class CoreBundleContext;


}

//-------------------------------------------------------------------
// Generic utility functions
//-------------------------------------------------------------------

namespace us {

// A convenient way to construct a shared_ptr holding an array
template<typename T> std::shared_ptr<T> make_shared_array(std::size_t size)
{
  return std::shared_ptr<T>(new T[size], std::default_delete<T[]>());
}

}

//-------------------------------------------------------------------
// Error handling
//-------------------------------------------------------------------

namespace us {

int GetLastErrorNo();
std::string GetLastErrorStr();

}

#endif // USUTILS_H
