//////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2018 Corona Labs Inc.
// Contact: support@coronalabs.com
//
// This file is part of the Corona game engine.
//
// Commercial License Usage
// Licensees holding valid commercial Corona licenses may use this file in
// accordance with the commercial license agreement between you and 
// Corona Labs Inc. For licensing terms and conditions please contact
// support@coronalabs.com or visit https://coronalabs.com/com-license
//
// GNU General Public License Usage
// Alternatively, this file may be used under the terms of the GNU General
// Public license version 3. The license is as published by the Free Software
// Foundation and appearing in the file LICENSE.GPL3 included in the packaging
// of this file. Please review the following information to ensure the GNU 
// General Public License requirements will
// be met: https://www.gnu.org/licenses/gpl-3.0.html
//
// For overview and more information on licensing please refer to README.md
//
//////////////////////////////////////////////////////////////////////////////

#ifndef _Rtt_NativeWindowMode_H__
#define _Rtt_NativeWindowMode_H__

#include "Core/Rtt_Macros.h"


namespace Rtt
{

/// Provides pre-defined window mode types such as "normal", "minimized", "maximized", etc.
/// Used by Corona's Lua native.setProperty() and native.getProperty() function with the "windowMode" property key.
/// Intended to be used by Corona desktop apps for Mac and Windows.
class NativeWindowMode
{
	Rtt_CLASS_NO_COPIES(NativeWindowMode)

	private:
		NativeWindowMode();
		NativeWindowMode(const char *stringId);
		virtual ~NativeWindowMode();

	public:
		/// Represents a normal window on the desktop.
		static const NativeWindowMode kNormal;

		/// Indicates the window is minimized to the desktop's task bar.
		static const NativeWindowMode kMinimized;

		/// Indicates the window is maximized, covering the entire client area of the desktop. Only applies to Win32 apps.
		static const NativeWindowMode kMaximized;

		/// Indicates the window is displayed fullscreen, covering the entire screen.
		static const NativeWindowMode kFullscreen;

		/// Gets the unique string key for this window mode.
		/// This is the string that is passed to/from the native.set/getProperty() functions respectively.
		/// @returns Returns this window mode's unique Corona string ID.
		const char* GetStringId() const;

		/// Determines if this window mode matches the given one.
		/// @param value The window mode to be compared with.
		/// @returns Return true if the window modes match. Returns false if not.
		bool Equals(const NativeWindowMode &value) const;

		/// Determines if this window mode does not match the given one.
		/// @param value The window mode to be compared with.
		/// @returns Return true if the window modes do not match. Returns false if they do match.
		bool NotEquals(const NativeWindowMode &value) const;

		/// Determines if this window mode matches the given one.
		/// @param value The window mode to be compared with.
		/// @returns Return true if the window modes match. Returns false if not.
		bool operator==(const NativeWindowMode &value) const;

		/// Determines if this window mode does not match the given one.
		/// @param value The window mode to be compared with.
		/// @returns Return true if the window modes do not match. Returns false if they do match.
		bool operator!=(const NativeWindowMode &value) const;

		/// Fetches a pre-defined NativeWindowMode object matching the given unique Corona string ID.
		/// @param stringId The window mode's unique string ID such as "normal", "maximized", etc.
		/// @returns Returns a pointer to the matching NativeWindowMode object such as kNormal, kMaximized, etc.
		///          <p>
		///          Returns null if the given string ID was not recognized.
		static const NativeWindowMode* FromStringId(const char *stringId);

	private:
		/// The unique Corona string ID for this window mode.
		const char* fStringId;
};

} // namespace Rtt

#endif // _Rtt_NativeWindowMode_H__
