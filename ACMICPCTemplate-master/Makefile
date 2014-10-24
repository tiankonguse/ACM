latex: template.pdf
	mv template.pdf pdf/template.pdf
	rm -f *.dvi
	
xelatex: template_xelatex.pdf
	mv template_xelatex.pdf pdf/template_xelatex.pdf
	rm -f *.dvi
	
all: template.pdf template_xelatex.pdf
	mv template.pdf pdf/template.pdf
	mv template_xelatex.pdf pdf/template_xelatex.pdf
	rm -f *.dvi
	
template.pdf: template.dvi
	dvipdfmx $<

template.dvi: template.tex
	latex $<
	latex $<

template_xelatex.pdf: template_xelatex.tex
	xelatex $<
	xelatex $<
	
clean:
	rm -f *.pdf
	rm -f *.dvi
