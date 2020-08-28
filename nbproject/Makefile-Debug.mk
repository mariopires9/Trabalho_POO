#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Assalta.o \
	${OBJECTDIR}/Assaltante.o \
	${OBJECTDIR}/ComeMigalha.o \
	${OBJECTDIR}/Comunidade.o \
	${OBJECTDIR}/Configuracao.o \
	${OBJECTDIR}/Consola.o \
	${OBJECTDIR}/Cuidadora.o \
	${OBJECTDIR}/Exploradora.o \
	${OBJECTDIR}/Foge.o \
	${OBJECTDIR}/Formigas.o \
	${OBJECTDIR}/Interface.o \
	${OBJECTDIR}/Migalhas.o \
	${OBJECTDIR}/Mundo.o \
	${OBJECTDIR}/Ninho.o \
	${OBJECTDIR}/Passeia.o \
	${OBJECTDIR}/Persegue.o \
	${OBJECTDIR}/ProcuraMigalha.o \
	${OBJECTDIR}/Protege.o \
	${OBJECTDIR}/Regra.o \
	${OBJECTDIR}/Simulacao.o \
	${OBJECTDIR}/Surpresa.o \
	${OBJECTDIR}/VaiParaNinho.o \
	${OBJECTDIR}/Vigilante.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tp_poo.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tp_poo.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tp_poo ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Assalta.o: Assalta.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Assalta.o Assalta.cpp

${OBJECTDIR}/Assaltante.o: Assaltante.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Assaltante.o Assaltante.cpp

${OBJECTDIR}/ComeMigalha.o: ComeMigalha.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ComeMigalha.o ComeMigalha.cpp

${OBJECTDIR}/Comunidade.o: Comunidade.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Comunidade.o Comunidade.cpp

${OBJECTDIR}/Configuracao.o: Configuracao.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Configuracao.o Configuracao.cpp

${OBJECTDIR}/Consola.o: Consola.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Consola.o Consola.cpp

${OBJECTDIR}/Cuidadora.o: Cuidadora.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Cuidadora.o Cuidadora.cpp

${OBJECTDIR}/Exploradora.o: Exploradora.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Exploradora.o Exploradora.cpp

${OBJECTDIR}/Foge.o: Foge.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Foge.o Foge.cpp

${OBJECTDIR}/Formigas.o: Formigas.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Formigas.o Formigas.cpp

${OBJECTDIR}/Interface.o: Interface.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Interface.o Interface.cpp

${OBJECTDIR}/Migalhas.o: Migalhas.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Migalhas.o Migalhas.cpp

${OBJECTDIR}/Mundo.o: Mundo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Mundo.o Mundo.cpp

${OBJECTDIR}/Ninho.o: Ninho.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Ninho.o Ninho.cpp

${OBJECTDIR}/Passeia.o: Passeia.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Passeia.o Passeia.cpp

${OBJECTDIR}/Persegue.o: Persegue.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Persegue.o Persegue.cpp

${OBJECTDIR}/ProcuraMigalha.o: ProcuraMigalha.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProcuraMigalha.o ProcuraMigalha.cpp

${OBJECTDIR}/Protege.o: Protege.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Protege.o Protege.cpp

${OBJECTDIR}/Regra.o: Regra.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Regra.o Regra.cpp

${OBJECTDIR}/Simulacao.o: Simulacao.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Simulacao.o Simulacao.cpp

${OBJECTDIR}/Surpresa.o: Surpresa.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Surpresa.o Surpresa.cpp

${OBJECTDIR}/VaiParaNinho.o: VaiParaNinho.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VaiParaNinho.o VaiParaNinho.cpp

${OBJECTDIR}/Vigilante.o: Vigilante.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Vigilante.o Vigilante.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
