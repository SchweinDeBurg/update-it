@ECHO OFF

REM UpdateIt! application.
REM Copyright (c) 2002-2009 by Elijah Zarezky,
REM All rights reserved.

REM Licensed under the Apache License, Version 2.0 (the "License");
REM you may not use this file except in compliance with the License.
REM You may obtain a copy of the License at
REM
REM http://www.apache.org/licenses/LICENSE-2.0
REM
REM Unless required by applicable law or agreed to in writing, software
REM distributed under the License is distributed on an "AS IS" BASIS,
REM WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
REM See the License for the specific language governing permissions and
REM limitations under the License.

REM gbuild.cmd - NT command script to perform deveopment build for Google Code

nant.exe -f:UpdateIt.2008.build @NAntSettings.txt -D:CommitMsg="Development build for Google Code." rebuild-all commit-src
