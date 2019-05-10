#!/bin/bash
echo "Using aliroot "
echo `which aliroot`
runs=`cat $1`
inputDir=$2
outputDir=$3
nworkers=$4
task=$5
generator=$6
mkdir -p $outputDir
mkdir -p $outputDir/logs
mkdir -p $outputDir/runLists
mkdir -p $outputDir/runs
cp AddTask_$task.C $outputDir
for i in `seq 1 $nworkers`; do
   > $outputDir/runLists/runList.$i.txt
done
currentFile=1
for run in $runs; do
   content=`cat $outputDir/runLists/runList.$currentFile.txt`
   printf "$content\n$run" > $outputDir/runLists/runList.$currentFile.txt
   let currentFile=currentFile+1
   if [ $currentFile -gt $nworkers ]; then
      currentFile=1
   fi
done
workDir=$PWD
sbatch --mem-per-cpu=1024 --array=1-$nworkers --time=2:00:00 -o $outputDir/logs/worker%a.out -e $outputDir/logs/worker%a.err $workDir/runAnalysis.sh $inputDir $outputDir  $task $generator &
