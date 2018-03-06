zinhart; % load module
topology = zinhart.UIntVector(3); % c++ std vector
training_data = zinhart.new_string("training_data/out_or.txt"); 
training_results = zinhart.zstring("training_data/resultOrTraining.txt");
testing_results = zinhart.zstring("training_data/resultOrTesting.txt");  
mynet = zinhart.net(topology,training_data,training_results); % artificial neural net

%train model here

disp(mynet.getTrainingDataFile());
disp(mynet.getTestingDataFile());
clear zinhart;%remove module
clear classes;
