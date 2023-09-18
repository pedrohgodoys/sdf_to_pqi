# SDF2PQI (_SDF to PQI Library Converter_)

> _In production._

## Progenesis QI and Structure-Data files (SDF) incompatibility

[Progenesis™ QI v2.4](https://www.nonlinear.com/progenesis/qi/v2.4/fraq/) (PQI, Waters Corporation™ © Nonlinear Dynamics) is a bioinformatic/chemometric tool that processes raw data from high-resolution Mass Spectrometry (MS). It facilitates the identification workflow for Metabolomics experiments using molecule libraries with Precursor's structure (structure-data file, _.sdf_) and its Fragments (main spectra profile, _.msp_) for _features_ annotation (identification).

PQI has several ways to search for molecule matches, using mainly internal molecule libraries but also, not officially, external libraries. The main spectra repository available are [The Human Metabolome Database](https://hmdb.ca/) (HMDB), [Lipid Maps](https://lipidmaps.org/) and [MassBank of North America](https://mona.fiehnlab.ucdavis.edu/) (MoNA), which considerably increases the number and quality of metabole identification. 

Due to its non-official nature, a lot of problems have been shown, the main reason being the differences in the formatting of external _.sdf_ file and internal _.sdf_ files used by PQI. Also, this formatting problem causes failure in the crosstalk between _.sdf_ and _.msp_ files, essential to relate the Precursor Ion with its Fragments for identifying unknown metabolites.

## Solution

We developed a console application, names _SDF2PQI_ (SDF to PQI Library Converter) to solve these formatting problems, enabling compatibility among SDF libraries and PQI and making them readily available to increase PQI's capabilities.

### Instructions
1. Go to the SDF download page ([HMDB](https://hmdb.ca/downloads); [Lipid Maps](https://lipidmaps.org/databases/lmsd/download); [MoNA](https://mona.fiehnlab.ucdavis.edu/downloads)) and download the "SDF" (_structure-data file_). It will be downloaded as a _.zip_ file, corresponding to the library you prefered.
2. Extract the _.zip_ file.
3. Inside de **SDF to PQI Converter** Folder, open the _.sdf_ file and save it as _"input.txt"_.
4. Click on the "sdf_to_pqi.exe" executable (_.exe_) file.
5. A command prompt will show up. **Don't close it.** The file's lines will be scanned and corrected. Wait until the conversion process is done.
6. Converted files will be generated as _"output.sdf"_ and _"output.msp"_.
7. **They are read to be used in Progenesis QI Metascope identification search.**
9. Every time a library will ber converted, should be only one _input.txt_ file inside the folder. We recommend you move the _output_ files from there.
____

> Citation: Sanches _et al._, Fitting Structure-Data Files (.SDF) Libraries to Progenesis QI Identification Searches. _J. Braz. Chem. Soc. 2023_.
>
> DOI: [10.21577/0103-5053.20230016](https://dx.doi.org/10.21577/0103-5053.20230016).

**Main Authors:** [Pedro H. Godoy Sanches](https://github.com/pedrohgodoys/), [Ivan G. M. dos Reis](https://github.com/igmdr/) and [Gustavo H. B. Duarte](https://github.com/GustavoHBDuarte/).
