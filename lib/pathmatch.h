/* -*- C++ -*-
 * Cppcheck - A tool for static C/C++ code analysis
 * Copyright (C) 2007-2024 Cppcheck team.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PATHMATCH_H
#define PATHMATCH_H

#include "config.h"

#include <string>
#include <vector>

/// @addtogroup CLI
/// @{

/**
 * @brief Simple path matching for ignoring paths in CLI.
 */
class CPPCHECKLIB PathMatch {
public:

    /**
     * The constructor.
     *
     * If a path is a directory it needs to end with a file separator.
     *
     * @param paths List of masks.
     * @param caseSensitive Match the case of the characters when
     *   matching paths?
     */
    explicit PathMatch(std::vector<std::string> paths, bool caseSensitive = true);

    /**
     * @brief Match path against list of masks.
     *
     * If you want to match a directory the given path needs to end with a path separator.
     *
     * @param path Path to match.
     * @return true if any of the masks match the path, false otherwise.
     */
    bool match(const std::string &path) const;

protected:

    /**
     * @brief Remove filename part from the path.
     * @param path Path to edit.
     * @return path without filename part.
     */
    static std::string removeFilename(const std::string &path);

private:
    std::vector<std::string> mPaths;
    bool mCaseSensitive;
    std::vector<std::string> mWorkingDirectory;
};

/// @}

#endif // PATHMATCH_H
