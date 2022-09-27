SUBMIT_FILES=functions.c functions.h Makefile solutions.a test.c

# Create a directory for submission files
$(USER):
	mkdir -p $(USER) 

# Copy submission files, then archive them
$(USER).tar: $(USER) $(SUBMIT_FILES)
	cp -v $(SUBMIT_FILES) $<
	tar -cv -f $@ $<

feedback.log: test
	(date && whoami) | tee -a feedback.log
	$(PWD)/test 2>&1 | tee -a feedback.log

# This is the make target for grader use.
# The grader should execute with `make -k check` 
# in order to continue past test errors.
.PHONY: check
check: feedback.log

# WARNING: DO NOT CALL THIS UNLESS YOU HAVE ACCESS TO solutions.c
# (i.e. instructors and graders only)
.PHONY:really-clean
really-clean: clean
	rm -fv solutions.a feedback.log
