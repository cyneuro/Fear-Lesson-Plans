# Fear Learning Lesson Plans
#### Developed in the Neural Engineering Laboratory at the University of Missouri by Gregory Glickert

## Running the tutorials

### Google Colab
No local install is needed. Open a folder, open the `.ipynb` file, and click **Open in Colab**. The notebook installs the same pinned packages listed in `requirements.txt` when it detects Colab.

### Local running and development
Requires python, [Poetry](https://python-poetry.org/docs/#installation), and a C/C++ toolchain so `nrnivmodl` can compile `.mod` files.

To install the python environment you can run this command. You must first be in directory of this repo for the command to work.
```bash
poetry install
```
You can then compile every mod file using this command.
```bash
poetry run python scripts/compile_all_mods.py
```
Finally you can open the notebooks with this command or open the notebooks in your IDE of choice.
```bash
poetry run jupyter notebook
```

### Lesson 1 - [Introduction to Fear](/Lesson-1-What-is-Fear/What-is-Fear.ipynb)
### Lesson 2 - [Introduction to Tone and Shock](/Lesson-2-How-do-Tone-Shock-pair/Intro-to-Tone-Shock.ipynb)
### Lesson 3 - [Calcium learning](/Lesson-3-How-Ca-impacts-learning/Calcium-Rule.ipynb)
### Lesson 4 - [Putting everything together](/Lesson-4-1.4/D1.4.ipynb)
### Lesson 5 - [Introduction to Neural circuits](/Lesson-5-D2/betterD2.ipynb)
### Lesson 6 - [12 Cell](/Lesson-7-12-Cell/12_cell_amygdala_network.ipynb)
