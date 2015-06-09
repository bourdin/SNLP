import os,sys
def getcurrentrevision(code_dir):
	from subprocess import Popen, PIPE
	if (os.path.isdir(os.path.join(code_dir,".git"))):
		os.chdir(code_dir)
		gitproc = Popen(['git', 'rev-parse','HEAD'], stdout = PIPE)
		(stdout, stderr) = gitproc.communicate()
		gitversion = open(os.path.join(code_dir,"src/gitversion.c"), "w")
		gitversion.write('''const char *gitversion = "%s";\n'''%stdout.rstrip())
		try:
			petscdir = os.environ['PETSC_DIR']
			if (os.path.isdir(os.path.join(petscdir,".git"))):
				os.chdir(code_dir)
				gitproc = Popen(['git', 'rev-parse','HEAD'], stdout = PIPE)
				(stdout, stderr) = gitproc.communicate()
				gitversion.write('''const char *petscgitversion ="%s";\n'''%stdout.rstrip())
		except KeyError:
			gitversion.write('''const char *petscgitversion ="na";\n''')
		gitversion.close()

if __name__ == "__main__":
	getcurrentrevision(sys.argv[1])