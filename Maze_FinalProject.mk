##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=Maze_FinalProject
ConfigurationName      :=Release
WorkspacePath          :=C:/Users/david/CodeLite/Test
ProjectPath            :=C:/Users/david/CodeLite/Test/Maze_FinalProject
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=david
Date                   :=20/05/2019
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :="C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/g++.exe"
SharedObjectLinkerName :="C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/g++.exe" -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Maze_FinalProject.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :="C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/windres.exe"
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/ar.exe" rcu
CXX      := "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/g++.exe"
CC       := "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/gcc.exe"
CXXFLAGS := -std=c++14 -Wall -O2 -Wall $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/as.exe"


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/robotState_robotState.cpp$(ObjectSuffix) $(IntermediateDirectory)/robotState_standState.cpp$(ObjectSuffix) $(IntermediateDirectory)/mobileRobot_mobileRobot.cpp$(ObjectSuffix) $(IntermediateDirectory)/mobileRobot_wheeled.cpp$(ObjectSuffix) $(IntermediateDirectory)/maze_maze.cpp$(ObjectSuffix) $(IntermediateDirectory)/robotState_moveDownState.cpp$(ObjectSuffix) $(IntermediateDirectory)/mobileRobot_tracked.cpp$(ObjectSuffix) $(IntermediateDirectory)/robotState_moveLeftState.cpp$(ObjectSuffix) $(IntermediateDirectory)/robotState_moveUpState.cpp$(ObjectSuffix) $(IntermediateDirectory)/robotState_moveRightState.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Release"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Release"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/robotState_robotState.cpp$(ObjectSuffix): robotState/robotState.cpp $(IntermediateDirectory)/robotState_robotState.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/david/CodeLite/Test/Maze_FinalProject/robotState/robotState.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/robotState_robotState.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/robotState_robotState.cpp$(DependSuffix): robotState/robotState.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/robotState_robotState.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/robotState_robotState.cpp$(DependSuffix) -MM robotState/robotState.cpp

$(IntermediateDirectory)/robotState_robotState.cpp$(PreprocessSuffix): robotState/robotState.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/robotState_robotState.cpp$(PreprocessSuffix) robotState/robotState.cpp

$(IntermediateDirectory)/robotState_standState.cpp$(ObjectSuffix): robotState/standState.cpp $(IntermediateDirectory)/robotState_standState.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/david/CodeLite/Test/Maze_FinalProject/robotState/standState.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/robotState_standState.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/robotState_standState.cpp$(DependSuffix): robotState/standState.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/robotState_standState.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/robotState_standState.cpp$(DependSuffix) -MM robotState/standState.cpp

$(IntermediateDirectory)/robotState_standState.cpp$(PreprocessSuffix): robotState/standState.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/robotState_standState.cpp$(PreprocessSuffix) robotState/standState.cpp

$(IntermediateDirectory)/mobileRobot_mobileRobot.cpp$(ObjectSuffix): mobileRobot/mobileRobot.cpp $(IntermediateDirectory)/mobileRobot_mobileRobot.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/david/CodeLite/Test/Maze_FinalProject/mobileRobot/mobileRobot.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mobileRobot_mobileRobot.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mobileRobot_mobileRobot.cpp$(DependSuffix): mobileRobot/mobileRobot.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mobileRobot_mobileRobot.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mobileRobot_mobileRobot.cpp$(DependSuffix) -MM mobileRobot/mobileRobot.cpp

$(IntermediateDirectory)/mobileRobot_mobileRobot.cpp$(PreprocessSuffix): mobileRobot/mobileRobot.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mobileRobot_mobileRobot.cpp$(PreprocessSuffix) mobileRobot/mobileRobot.cpp

$(IntermediateDirectory)/mobileRobot_wheeled.cpp$(ObjectSuffix): mobileRobot/wheeled.cpp $(IntermediateDirectory)/mobileRobot_wheeled.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/david/CodeLite/Test/Maze_FinalProject/mobileRobot/wheeled.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mobileRobot_wheeled.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mobileRobot_wheeled.cpp$(DependSuffix): mobileRobot/wheeled.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mobileRobot_wheeled.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mobileRobot_wheeled.cpp$(DependSuffix) -MM mobileRobot/wheeled.cpp

$(IntermediateDirectory)/mobileRobot_wheeled.cpp$(PreprocessSuffix): mobileRobot/wheeled.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mobileRobot_wheeled.cpp$(PreprocessSuffix) mobileRobot/wheeled.cpp

$(IntermediateDirectory)/maze_maze.cpp$(ObjectSuffix): maze/maze.cpp $(IntermediateDirectory)/maze_maze.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/david/CodeLite/Test/Maze_FinalProject/maze/maze.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/maze_maze.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/maze_maze.cpp$(DependSuffix): maze/maze.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/maze_maze.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/maze_maze.cpp$(DependSuffix) -MM maze/maze.cpp

$(IntermediateDirectory)/maze_maze.cpp$(PreprocessSuffix): maze/maze.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/maze_maze.cpp$(PreprocessSuffix) maze/maze.cpp

$(IntermediateDirectory)/robotState_moveDownState.cpp$(ObjectSuffix): robotState/moveDownState.cpp $(IntermediateDirectory)/robotState_moveDownState.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/david/CodeLite/Test/Maze_FinalProject/robotState/moveDownState.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/robotState_moveDownState.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/robotState_moveDownState.cpp$(DependSuffix): robotState/moveDownState.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/robotState_moveDownState.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/robotState_moveDownState.cpp$(DependSuffix) -MM robotState/moveDownState.cpp

$(IntermediateDirectory)/robotState_moveDownState.cpp$(PreprocessSuffix): robotState/moveDownState.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/robotState_moveDownState.cpp$(PreprocessSuffix) robotState/moveDownState.cpp

$(IntermediateDirectory)/mobileRobot_tracked.cpp$(ObjectSuffix): mobileRobot/tracked.cpp $(IntermediateDirectory)/mobileRobot_tracked.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/david/CodeLite/Test/Maze_FinalProject/mobileRobot/tracked.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mobileRobot_tracked.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mobileRobot_tracked.cpp$(DependSuffix): mobileRobot/tracked.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mobileRobot_tracked.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mobileRobot_tracked.cpp$(DependSuffix) -MM mobileRobot/tracked.cpp

$(IntermediateDirectory)/mobileRobot_tracked.cpp$(PreprocessSuffix): mobileRobot/tracked.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mobileRobot_tracked.cpp$(PreprocessSuffix) mobileRobot/tracked.cpp

$(IntermediateDirectory)/robotState_moveLeftState.cpp$(ObjectSuffix): robotState/moveLeftState.cpp $(IntermediateDirectory)/robotState_moveLeftState.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/david/CodeLite/Test/Maze_FinalProject/robotState/moveLeftState.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/robotState_moveLeftState.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/robotState_moveLeftState.cpp$(DependSuffix): robotState/moveLeftState.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/robotState_moveLeftState.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/robotState_moveLeftState.cpp$(DependSuffix) -MM robotState/moveLeftState.cpp

$(IntermediateDirectory)/robotState_moveLeftState.cpp$(PreprocessSuffix): robotState/moveLeftState.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/robotState_moveLeftState.cpp$(PreprocessSuffix) robotState/moveLeftState.cpp

$(IntermediateDirectory)/robotState_moveUpState.cpp$(ObjectSuffix): robotState/moveUpState.cpp $(IntermediateDirectory)/robotState_moveUpState.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/david/CodeLite/Test/Maze_FinalProject/robotState/moveUpState.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/robotState_moveUpState.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/robotState_moveUpState.cpp$(DependSuffix): robotState/moveUpState.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/robotState_moveUpState.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/robotState_moveUpState.cpp$(DependSuffix) -MM robotState/moveUpState.cpp

$(IntermediateDirectory)/robotState_moveUpState.cpp$(PreprocessSuffix): robotState/moveUpState.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/robotState_moveUpState.cpp$(PreprocessSuffix) robotState/moveUpState.cpp

$(IntermediateDirectory)/robotState_moveRightState.cpp$(ObjectSuffix): robotState/moveRightState.cpp $(IntermediateDirectory)/robotState_moveRightState.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/david/CodeLite/Test/Maze_FinalProject/robotState/moveRightState.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/robotState_moveRightState.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/robotState_moveRightState.cpp$(DependSuffix): robotState/moveRightState.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/robotState_moveRightState.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/robotState_moveRightState.cpp$(DependSuffix) -MM robotState/moveRightState.cpp

$(IntermediateDirectory)/robotState_moveRightState.cpp$(PreprocessSuffix): robotState/moveRightState.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/robotState_moveRightState.cpp$(PreprocessSuffix) robotState/moveRightState.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/david/CodeLite/Test/Maze_FinalProject/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Release/


