;; UpdateIt! application.
;; Copyright (c) 2002-2009 by Elijah Zarezky,
;; All rights reserved.

;; Licensed under the Apache License, Version 2.0 (the "License");
;; you may not use this file except in compliance with the License.
;; You may obtain a copy of the License at
;;
;; http://www.apache.org/licenses/LICENSE-2.0
;;
;; Unless required by applicable law or agreed to in writing, software
;; distributed under the License is distributed on an "AS IS" BASIS,
;; WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
;; See the License for the specific language governing permissions and
;; limitations under the License.

;; Setup.iss - setup script for Inno Setup compiler
;; NOTE that this file is generated automatically by NAnt.exe

[Setup]
AppName=UpdateIt!
AppVerName=UpdateIt! @VER_MAJOR@.@VER_MINOR@.@VER_BUILD@
AppID={{78461E4F-C4AD-4488-97F7-773CCA325839}
AppPublisher=Elijah Zarezky
AppPublisherURL=http://zarezky.spb.ru/
AppSupportURL=http://zarezky.spb.ru/projects/update_it.html
AppUpdatesURL=http://zarezky.spb.ru/projects/update_it.html
AppVersion=@VER_MAJOR@.@VER_MINOR@.@VER_BUILD@
DefaultDirName={pf}\Elijah Zarezky\UpdateIt
DefaultGroupName=Elijah Zarezky\UpdateIt
AllowNoIcons=true
Compression=lzma
SolidCompression=true
OutputDir=..\Setup
OutputBaseFilename=UpdateIt-@VER_MAJOR@.@VER_MINOR@.@VER_BUILD@-setup
VersionInfoVersion=@VER_MAJOR@.@VER_MINOR@.@VER_BUILD@
MinVersion=4.1.2222,5.0.2195
WizardImageFile=compiler:WizModernImage-IS.bmp
WizardSmallImageFile=compiler:WizModernSmallImage-IS.bmp
LicenseFile=ApacheLicense.rtf
LanguageDetectionMethod=none
ShowLanguageDialog=yes
AppMutex=UpdateIt.Instance.03E2CBEF-1504-45d8-8BD2-79719D32E29F

[Languages]
;; English
Name: "en"; MessagesFile: "compiler:Default.isl"
;; Russian
Name: "ru"; MessagesFile: "compiler:Languages\Russian.isl"; LicenseFile: ".\ApacheLicense.rtf"

[LangOptions]
LanguageCodePage=0
DialogFontName=MS Shell Dlg 2
DialogFontSize=8
en.LanguageName=English
ru.LanguageName=Russian

[Messages]
SelectLanguageTitle=Language Selection
SelectLanguageLabel=Please select UpdateIt! language:

[Code]
function NextButtonClick(CurPageID: Integer): Boolean;
var
	hRootHive: Integer;
	LangsKeyName: String;
begin
	if (CurPageID = wpReady) then
	begin
		hRootHive := HKEY_CURRENT_USER;
		LangsKeyName := 'Software\Elijah Zarezky\UpdateIt!\Languages';

		RegWriteStringValue(hRootHive, LangsKeyName + '\en', '', '.\mfc90enu.dll');
		RegWriteStringValue(hRootHive, LangsKeyName + '\en', 'LangDLL', '.\English_USA.1252.dll');
		RegWriteStringValue(hRootHive, LangsKeyName + '\ru', '', '.\mfc90rus.dll');
		RegWriteStringValue(hRootHive, LangsKeyName + '\ru', 'LangDLL', '.\Russian_Russia.1251.dll');
		
		RegWriteStringValue(hRootHive, LangsKeyName, '', 'en;ru');
		RegWriteStringValue(hRootHive, LangsKeyName, 'Current', ActiveLanguage());
	end;
	
	Result := True;
end;

[InstallDelete]
;; from 1.4 release
Type: files; Name: "{app}\msvcr71.dll"
Type: files; Name: "{app}\msvcp71.dll"
Type: files; Name: "{app}\mfc71.dll"
Type: files; Name: "{app}\mfc71enu.dll"
Type: files; Name: "{app}\mfc71rus.dll"
Type: filesandordirs; Name: "{app}\Languages"
Type: files; Name: "{app}\UpdateIt.chm"
;; from 1.5 pre-release
Type: filesandordirs; Name: "{app}\Microsoft.VC90.CRT"
Type: filesandordirs; Name: "{app}\Microsoft.VC90.MFC"

[Files]
;; core application files
Source: "..\Output.2008\x86\@BUILD_TYPE@\@CHARACTER_SET@\UpdateIt.exe"; DestDir: "{app}"
Source: "..\HTML\UpdateIt.0409.chm"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\HTML\UpdateIt.0419.chm"; DestDir: "{app}"; Flags: ignoreversion
Source: ".\ApacheLicense.rtf"; DestDir: "{app}"; Flags: ignoreversion

;; application localizations
Source: "..\Languages\English_USA.1252\Output.2008\x86\@BUILD_TYPE@\@CHARACTER_SET@\English_USA.1252.dll"; DestDir: "{app}"
Source: "..\Languages\Russian_Russia.1251\Output.2008\x86\@BUILD_TYPE@\@CHARACTER_SET@\Russian_Russia.1251.dll"; DestDir: "{app}"

;; CRT redistributables
Source: "..\Redist\Microsoft.VC90.CRT\msvcr90.dll"; DestDir: "{app}";
Source: "..\Redist\Microsoft.VC90.CRT\msvcp90.dll"; DestDir: "{app}";
Source: "..\Redist\Microsoft.VC90.CRT\msvcm90.dll"; DestDir: "{app}";
Source: "..\Redist\Microsoft.VC90.CRT\Microsoft.VC90.CRT.manifest"; DestDir: "{app}"; MinVersion: 0,5.01.2600

;; MFC library redistributables
Source: "..\Redist\Microsoft.VC90.MFC\mfc90.dll"; DestDir: "{app}";
Source: "..\Redist\Microsoft.VC90.MFC\mfcm90.dll"; DestDir: "{app}";
Source: "..\Redist\Microsoft.VC90.MFC\Microsoft.VC90.MFC.manifest"; DestDir: "{app}"; MinVersion: 0,5.01.2600

;; MFC library localizations
Source: "..\Redist\Microsoft.VC90.MFCLOC\mfc90enu.dll"; DestDir: "{app}";
Source: "..\Redist\Microsoft.VC90.MFCLOC\mfc90rus.dll"; DestDir: "{app}";
Source: "..\Redist\Microsoft.VC90.MFCLOC\Microsoft.VC90.MFCLOC.manifest"; DestDir: "{app}"; MinVersion: 0,5.01.2600

;; OpenSSL redistributables
Source: "..\..\Repository\OpenSSL\redist\ssleay32.dll"; DestDir: "{app}"
Source: "..\..\Repository\OpenSSL\redist\libeay32.dll"; DestDir: "{app}"

[Icons]
Name: "{group}\UpdateIt!"; Filename: "{app}\UpdateIt.exe"; WorkingDir: "{app}"
Name: "{group}\Documentation (English)"; Filename: "{app}\UpdateIt.0409.chm"; Languages: en
Name: "{group}\������������ (�� ����������)"; Filename: "{app}\UpdateIt.0409.chm"; Languages: ru
Name: "{group}\Documentation (Russian)"; Filename: "{app}\UpdateIt.0419.chm"; Languages: en
Name: "{group}\������������ (�� �������)"; Filename: "{app}\UpdateIt.0419.chm"; Languages: ru
Name: "{group}\License Agreement"; Filename: "{app}\ApacheLicense.rtf"; Languages: en
Name: "{group}\������������ ����������"; Filename: "{app}\ApacheLicense.rtf"; Languages: ru
Name: "{group}\UpdateIt! on the Web"; Filename: "{app}\UpdateIt.url"; Languages: en
Name: "{group}\UpdateIt! � ��������"; Filename: "{app}\UpdateIt.url"; Languages: ru
Name: "{group}\Uninstall UpdateIt!"; Filename: "{uninstallexe}"; Languages: en
Name: "{group}\������� UpdateIt!"; Filename: "{uninstallexe}"; Languages: ru
Name: "{userdesktop}\UpdateIt!"; Filename: "{app}\UpdateIt.exe"; WorkingDir: "{app}"; Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\UpdateIt!"; Filename: "{app}\UpdateIt.exe"; WorkingDir: "{app}"; Tasks: quicklaunchicon

[INI]
Filename: "{app}\UpdateIt.url"; Section: "InternetShortcut"; Key: "URL"; String: "http://zarezky.spb.ru/projects/update_it.html"

[Registry]
Root: HKCU; Subkey: "Software\Elijah Zarezky"; Flags: uninsdeletekeyifempty
Root: HKCU; Subkey: "Software\Elijah Zarezky\UpdateIt!"; Flags: uninsdeletekey
Root: HKCU; Subkey: "Software\Elijah Zarezky\UpdateIt!\Locale"; Flags: uninsdeletekey
Root: HKCU; Subkey: "Software\Elijah Zarezky\UpdateIt!\Locale"; ValueType: string; ValueName: "LC_ALL"; ValueData: "English_USA.1252"; Flags: createvalueifdoesntexist; Languages: en
Root: HKCU; Subkey: "Software\Elijah Zarezky\UpdateIt!\Locale"; ValueType: string; ValueName: "LC_ALL"; ValueData: "Russian_Russia.1251"; Flags: createvalueifdoesntexist; Languages: ru
Root: HKCU; Subkey: "Software\Elijah Zarezky\UpdateIt!\Options"; Flags: uninsdeletekey
Root: HKCU; Subkey: "Software\Elijah Zarezky\UpdateIt!\Options"; ValueType: string; ValueName: "Exclude"; ValueData: "*\.svn\*.*,*.obj,*.pch,*.sbr,*.res,*.tlb,*.bsc,*.idb,*.pdb,*.plg,*.aps,*.opt,*.ncb,*.exe,*.dll,*.ocx,*.lib"; Flags: createvalueifdoesntexist
Root: HKCU; Subkey: "Software\Elijah Zarezky\UpdateIt!\SMTP"; Flags: uninsdeletekey
Root: HKCU; Subkey: "Software\Elijah Zarezky\UpdateIt!\SMTP"; ValueType: string; ValueName: "charset"; ValueData: "windows-1252"; Flags: createvalueifdoesntexist; Languages: en
Root: HKCU; Subkey: "Software\Elijah Zarezky\UpdateIt!\SMTP"; ValueType: string; ValueName: "charset"; ValueData: "windows-1251"; Flags: createvalueifdoesntexist; Languages: ru
Root: HKCU; Subkey: "Software\Elijah Zarezky\UpdateIt!\SMTP"; ValueType: dword; ValueName: "Enable"; ValueData: "1"; Flags: createvalueifdoesntexist

[Tasks]
Name: desktopicon; Description: "Create a &desktop icon"; GroupDescription: "Additional icons:"; Flags: unchecked
Name: quicklaunchicon; Description: "Create a &Quick Launch icon"; GroupDescription: "Additional icons:"; Flags: unchecked

[Run]
Filename: "{app}\UpdateIt.exe"; Description: "Launch UpdateIt!"; Flags: nowait postinstall skipifsilent

[UninstallDelete]
Type: files; Name: "{app}\UpdateIt.url"

;; end of file