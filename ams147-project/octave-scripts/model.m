zinhart; % load module
topology = zinhart.UIntVector(3); % c++ std vector
training_data = zinhart.zstring("training_data/out_or.txt"); 
training_results = zinhart.zstring("training_data/resultOrTraining.txt");
testing_results = zinhart.zstring("training_data/resultOrTesting.txt");  
mynet = zinhart.net(topology,training_data,training_results); % artificial neural net

%train model here

disp(mynet.get_training_data_file());
disp(mynet.get_testing_data_file());
clear zinhart;%remove module
clear classes;
