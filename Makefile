PROJECT=mandelbrot

$(PROJECT): $(PROJECT).c
	gcc $< -o $@ -lm -lGL -lGLU -lglut

clean:
	rm $(PROJECT)

exec: $(PROJECT)
	./$<
