# -----------------------------------------------------------------------
#
#  MAKE-file to build IPANEMA Applikation 
#
#  usage:	Befor using please adapt the path regarding to your system-configuration
#		please adapt in Makefile.(nt linux ...):
#				IPANEMA_PATH,
#				SOFTWARE_ROOT_PATH,
#				SOFTWARE_INCLUDE_PATH,
#				COMPILER_INCLUDE_PATH, 
#				COMPILER_INCLUDES
#		generate	make [ 
#							mpc5200pxros, debug, all ]
#		delete		make [clean]
#
#  bugs:	changes in any *.h file are not recognized
# -----------------------------------------------------------------------


# -----------------------------------------------------------------------
#  defs
# -----------------------------------------------------------------------


export TARGET_SPECIFIC_PATH = $(CURDIR)
export TARGET_SOURCE_PATH = $(CURDIR)/src
export IPANEMA_FRAMEWORK_PATH = $(abspath $(CURDIR)/../../iXnitionFramework/Ipanema)
export CEPHES_MATH_PATH = $(abspath $(CURDIR)/../../../CV-Base/cephes-math/cephes-math_dll/src)

SETUP_BUILDFILES = ip_lib.a sim.a sys_layer_mpc5200.a
SETUPDIR_BASE = ../SetupFiles/development/IPANEMALIB1.1/
SETUPDIR_BUILDS = $(SETUPDIR_BASE)/lib/mpc5200_pxros_uboot
SETUPDIR_INCLUDES = $(SETUPDIR_BASE)/include/syslayer/mpc5200_pxros_uboot

EXPECTED_BUILD_FILES = $(SETUP_BUILDFILES)

	MAKE_FILE	=	makefile

#$(abspath ) löst den Pfad so auf, dass keine .. oder // mehr vorkommen

# -----------------------------------------------------------------------
#  rules
# -----------------------------------------------------------------------

#Das Defaulttarget
release_double_float:
	cd $(TARGET_SOURCE_PATH); $(MAKE) -f $(MAKE_FILE)
	@for F in $(EXPECTED_BUILD_FILES) ; do \
		if [ ! -e $(CURDIR)/build/release/$$F ]; \
		then \
			echo "Build Error: $$F has not been created!"; \
		fi;\
	done

release_double_float_cache:
	cd $(TARGET_SOURCE_PATH); $(MAKE) activate_cache=1 -f $(MAKE_FILE)
	@for F in $(EXPECTED_BUILD_FILES) ; do \
		if [ ! -e $(CURDIR)/build/release_cache/$$F ]; \
		then \
			echo "Build Error: $$F has not been created!"; \
		fi;\
	done
	
release: release_double_float release_double_float_cache release_single_float release_single_float_cache


#Achtung! Beim Target 'all' wird dieses Makefile rekursiv aufgerufen. Einmal mit und ein mal ohne debug
all:
	$(MAKE)
	$(MAKE) debug
	$(MAKE) release_single_float
	$(MAKE) debug_single_float

#Achtung! Beim Target 'debug' wird dieses Makefile rekursiv mit dem Parameter 'debug=1' aufgerufen. 
#Das wird auch vom toplevel Makefile so aufgerufen
debug_double_float: 
	cd $(TARGET_SOURCE_PATH); $(MAKE) debug=1 -f $(MAKE_FILE)
	@for F in $(EXPECTED_BUILD_FILES) ; do \
		if [ ! -e $(CURDIR)/build/debug/$$F ]; \
		then \
			echo "Build Error: $$F has not been created!"; \
		fi;\
	done

debug: debug_double_float debug_single_float

release_single_float:
	#build
	cd $(TARGET_SOURCE_PATH); $(MAKE) singlefloat=1 -f $(MAKE_FILE)
	@for F in $(EXPECTED_BUILD_FILES) ; do \
		if [ ! -e $(CURDIR)/build/singlefloat_release/$$F ]; \
		then \
			echo "Build Error: $$F has not been created!"; \
		fi;\
	done

release_single_float_cache:
	#build
	cd $(TARGET_SOURCE_PATH); $(MAKE) singlefloat=1 activate_cache=1 -f $(MAKE_FILE)
	@for F in $(EXPECTED_BUILD_FILES) ; do \
		if [ ! -e $(CURDIR)/build/singlefloat_release_cache/$$F ]; \
		then \
			echo "Build Error: $$F has not been created!"; \
		fi;\
	done

debug_single_float:
	cd $(TARGET_SOURCE_PATH); $(MAKE) debug=1 singlefloat=1 -f $(MAKE_FILE)
	@for F in $(EXPECTED_BUILD_FILES) ; do \
		if [ ! -e $(CURDIR)/build/singlefloat_debug/$$F ]; \
		then \
			echo "Build Error: $$F has not been created!"; \
		fi;\
	done

clean_all: 
	$(MAKE) clean_debug
	$(MAKE) clean_release
	$(MAKE) clean_debug_single_float
	$(MAKE) clean_release_single_float

clean_release: clean_release_double_float clean_release_single_float

clean_release_double_float:
	cd $(TARGET_SOURCE_PATH); $(MAKE) clean -f $(MAKE_FILE)

clean_release_double_float_cache:
	cd $(TARGET_SOURCE_PATH); $(MAKE) clean activate_cache=1 -f $(MAKE_FILE)

clean_release_single_float:
	cd $(TARGET_SOURCE_PATH); $(MAKE) clean singlefloat=1 -f $(MAKE_FILE)

clean_release_single_float_cache:
	cd $(TARGET_SOURCE_PATH); $(MAKE) clean singlefloat=1 activate_cache=1 -f $(MAKE_FILE)


clean_debug: clean_debug_double_float clean_debug_single_float

clean_debug_double_float:
	cd $(TARGET_SOURCE_PATH); $(MAKE) clean debug=1 -f $(MAKE_FILE)

clean_debug_single_float:
	cd $(TARGET_SOURCE_PATH); $(MAKE) clean debug=1 singlefloat=1 -f $(MAKE_FILE)


#Kopieren der Libs in das Setup Files Verzeichnis
setupfiles:
	mkdir -p $(SETUPDIR_BUILDS)/release
	mkdir -p $(SETUPDIR_BUILDS)/debug
	mkdir -p $(SETUPDIR_BUILDS)/singlefloat_release
	mkdir -p $(SETUPDIR_BUILDS)/singlefloat_debug
	cp $(addprefix build/release/, $(SETUP_BUILDFILES)) $(SETUPDIR_BUILDS)/release
	cp $(addprefix build/debug/, $(SETUP_BUILDFILES)) $(SETUPDIR_BUILDS)/debug
	cp $(addprefix build/singlefloat_release/, $(SETUP_BUILDFILES)) $(SETUPDIR_BUILDS)/singlefloat_release
	cp $(addprefix build/singlefloat_debug/, $(SETUP_BUILDFILES)) $(SETUPDIR_BUILDS)/singlefloat_debug
	mkdir -p $(SETUPDIR_INCLUDES)
	cp -r include/syslayer/* $(SETUPDIR_INCLUDES)
	

help:
	@echo 1: Funktionen für das aktuelle Betriebssystem
	@echo	[make]  
	@echo	[make release]
	@echo	[make debug]
	@echo	[make release_single_float]
	@echo	[make debug_single_float]
	@echo	[make clean_all]
	@echo	[make clean_release]
	@echo	[make clean_debug]
	@echo	[make clean_release_single_float]
	@echo	[make clean_debug_single_float]
	@echo	[make all]
	@echo	[make setupfiles]
	@echo -------------------------------------------------------------------------
	@echo TARGET_SPECIFIC_PATH is set to $(TARGET_SPECIFIC_PATH)
	@echo TARGET_SOURCE_PATH is set to $(TARGET_SOURCE_PATH)
	@echo IPANEMA_FRAMEWORK_PATH is set to $(IPANEMA_FRAMEWORK_PATH)
	@echo CEPHES_MATH_PATH is set to $(CEPHES_MATH_PATH)
	@echo --------------------------------------------------------------------------
