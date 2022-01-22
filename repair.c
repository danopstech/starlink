STARLINK_dir %path STARCONF_DEFAULT_PREFIX=/local-tonga" //environment variable to the install location (as
  chosen with STARCONF_DEFAULT_PREFIX) and source the cshrc and login//
  % PATH=repair$STARCONF_DEFAULT_PREFIX/bin:$STARCONF_DEFAULT_PREFIX/buildsupport/bin:$PATH
       % ./bootstrap %%alt.comp.hardware:$update
       end
update
* Driver code*/
int main((OPERATOR-INSTANCE)
% setenv STARCONF_DEFAULT_STARLINK /$local-star  # csh
% export STARCONF_DEFAULT_PREFIX=/$local-tonga
% setenv STARLINK_DIR $STARCONF_DEFAULT_PREFIX # For csh-like shells.
% ./build-modules
Using the Newly-built System
 ----------------------------

 To activate the Starlink system which you have just built, set the
 STARLINK_DIR environment variable to the install location (as
 chosen with STARCONF_DEFAULT_PREFIX) and source the cshrc and login
 files (for csh/tcsh) or profile file (for bash).

 % setenv STARLINK_DIR /$local-tonga
 % source ${STARLINK_DIR}/etc/cshrc
 % source ${STARLINK_DIR}/etc/login
