// Homework 3 Assignment - Course Schedule
// Jason Hsu
// 2580964804

#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <iomanip>
#include <fstream>  //read file as input

using namespace std;

bool readFile();

struct Room
{
	char building_code[3];
	int room_number;
	int max_students;
};

struct Course
{
	char prefix[5];
	int course_number;
	int num_minutes;
	int num_lectures;
};

struct Section_Constraints
{
	int days[7]; // see explanation below
	int earliest_start_time;
	int latest_end_time;
};

struct Section
{
	int section_id;
	int section_number;
	int num_students;
	Course course;
	Section_Constraints constraints;
};

//Here is my struct for keeping track of the scheduled sections. The code 
//below assumes this structure. You will have to dynamically create an
//array of this structure and call it 'scheduledSections'. See below.
struct Scheduled_Sections {
	int section_id;
	int section_num;
	string prefix;
	int course_number;
	int startTime;
	int endTime;
	int days[7];
	int num_students;
	Room room;
};


const string BUILDINGHEADING = "-- building room_number capacity";
const string COURSEHEADING = "-- ID prefix course# sect# #minutes #mtgsperweek #students";
const string DAYHEADING = "-- ID days_constraint start_contraint end_constraint";

Room *allRooms = NULL;
Section *allSections = NULL;
Scheduled_Sections *scheduledSections;  //You must size the array correctly
int scheduledCount = 0, roomCount = 0, sectionCount = 0;

int fixTime(int actualStartTime, int num_minutes);
bool daysMatch(int *scheduledDays, int *constraintDays);
bool roomsMatch(Room scheduledRoom, Room thisRoom);
int timesOverlap(int scheduledStartTime, int scheduledEndTime, int constraintStartTime, int constraintEndTime, int numMinutes);
bool scheduleSections();
bool scheduleAvailable(Section sectionToSchedule, int roomIndex);
void printByCourse();
void printScheduledSections();

int main()
{
	bool isGoodData = false;
	cout << "Welcome to the classroom assignment program!" << endl;
	while (!isGoodData)
		isGoodData = readFile();
	scheduleSections(); 
	printByCourse();
	printScheduledSections();
	return 0;
}

//readFile function; re-prompts user to input if input is invalid
bool readFile()
{
	char filename[100];

	ifstream fin;
	cout << "Enter the input file: ";
	cin >> filename;   //no longer limits the input to be input.txt only
	fin.open(filename);
	if (fin.fail())
	{
		cout << "Failed to open file. " << endl;
		return false;
	}
	string input;
	int count = 0;
	getline(fin, input);
	while (input != "" && !fin.fail())
	{
		getline(fin, input);
		count++;
	}

	if (allRooms != NULL)   //check if bad input is in memory
		delete[] allRooms;
	allRooms = new Room[count];

	while (input != COURSEHEADING && !fin.fail())
		getline(fin, input);
	while (input != "" && !fin.fail())
	{
		getline(fin, input);
		count++;
	}

	if (allSections != NULL)   //check if bad input is in memory
		delete[] allSections;
	allSections = new Section[count];

	fin.close();
	fin.open(filename);

	int i = 0;
	getline(fin, input);
	if (input != BUILDINGHEADING)
	{
		cout << "ERROR -- BUILDING INPUT" << endl;
		return false;
	}
	while (fin.peek() != '\n')
	{
		if (!(fin >> allRooms[i].building_code >> allRooms[i].room_number >> allRooms[i].max_students))
		{
			cout << "ERROR -- BAD DATA" << endl;
			return false;
		}
		fin.ignore(100, '\n');
		roomCount++;
		i++;
	}

	fin.ignore(100, '\n');
	getline(fin, input);

	if (input != COURSEHEADING)
	{
		cout << "ERROR -- COURSE INPUT" << endl;
		return false;
	}

	int j = 0, sid;
	while (fin.peek() != '\n')
	{
		if (!(fin >> allSections[j].section_id))
		{
			cout << "ERROR -- BAD DATA" << endl;
			return false;
		}
		fin.ignore(1);
		for (int m = 0; m < 4; m++)
			fin >> allSections[j].course.prefix[m];
		allSections[j].course.prefix[4] = '\0';
		if (!(fin >> allSections[j].course.course_number >> allSections[j].section_number >> allSections[j].course.num_minutes >> allSections[j].course.num_lectures >> allSections[j].num_students))
		{
			cout << "ERROR -- BAD DATA" << endl;
			return false;
		}
		fin.ignore(100, '\n');
		sectionCount++;
		j++;
	}

	fin.ignore(100, '\n');
	getline(fin, input);
	if (input != DAYHEADING)
	{
		cout << "ERROR -- RESTRICTIONS INPUT" << endl;
		return false;
	}
	while (!fin.fail())
	{
		fin >> sid;
		for (int k = 0; k < j; k++)
		{
			if (allSections[k].section_id == sid)
			{
				string days;
				fin >> days;
				for (int l = 0; l < 7; l++)
					allSections[k].constraints.days[l] = 0;
				for (unsigned int l = 0; l < days.length(); l++)
				{
					switch (days[l])
					{
					case 'M': allSections[k].constraints.days[0] = 1;
						break;
					case 'T': allSections[k].constraints.days[1] = 1;
						break;
					case 'W': allSections[k].constraints.days[2] = 1;
						break;
					case 'R': allSections[k].constraints.days[3] = 1;
						break;
					case 'F': allSections[k].constraints.days[4] = 1;
						break;
					case 'S': allSections[k].constraints.days[5] = 1;
						break;
					case 'U': allSections[k].constraints.days[6] = 1;
						break;
					default:
						cout << "ERROR -- BAD DATA" << endl;
						return false;
					}
				}
				if (!(fin >> allSections[k].constraints.earliest_start_time >> allSections[k].constraints.latest_end_time))
				{
					cout << "ERROR -- BAD DATA" << endl;
					return false;
				}
			}
		}
		fin.ignore(100, '\n');
	}
	/*
	for (int numBuild = 0; numBuild < i; numBuild++)
	{
		cout << "BUILDINGS: " << allRooms[numBuild].building_code << endl;
		cout << "MAX STUDENT: " << allRooms[numBuild].max_students << endl;
		cout << "ROOM #: " << allRooms[numBuild].room_number << endl << endl;
	}
	for (int numCourses = 0; numCourses < j; numCourses++)
	{
		cout << "SECTION ID: " << allSections[numCourses].section_id << endl;
		cout << "SECTION #: " << allSections[numCourses].section_number << endl;
		cout << "COURSE #: " << allSections[numCourses].course.course_number << endl;
		cout << "NUMSTUDENTS: " << allSections[numCourses].num_students << endl;
		cout << "NUMLECTURES: " << allSections[numCourses].course.num_lectures << endl;
		cout << "PREFIX: " << allSections[numCourses].course.prefix << endl;
		cout << "DAYS: ";
		for (int m = 0; m < 7; m++)
			cout << allSections[numCourses].constraints.days[m];
		cout << endl;
		cout << "START TIME: " << allSections[numCourses].constraints.earliest_start_time << endl;
		cout << "END TIME: " << allSections[numCourses].constraints.latest_end_time << endl << endl;
	}
	*/
	return true;
}

string printDays(int *days)
{
	string str = "";
	if (days[0] == 1)
		str += 'M';
	if (days[1] == 1)
		str += 'T';
	if (days[2] == 1)
		str += 'W';
	if (days[3] == 1)
		str += 'R';
	if (days[4] == 1)
		str += 'T';
	if (days[5] == 1)
		str += 'W';
	if (days[6] == 1)
		str += 'R';
	return str;
}

void printByCourse()
{
	cout << "SCHEDULE BY CLASS" << endl;
	cout << "-----------------" << endl << endl;

	int *cNo = new int[scheduledCount];
	for (int i = 0; i < scheduledCount; i++)
		cNo[i] = scheduledSections[i].course_number;
	for (int i = 0; i < scheduledCount - 1; i++)
	{
		int min = cNo[i], pos = i;
		for (int j = i + 1; j < scheduledCount; j++)
		{
			if (min > cNo[j])
			{
				min = cNo[j];
				pos = j;
			}
		}
		int temp = cNo[i];
		cNo[i] = cNo[pos];
		cNo[pos] = temp;
	}

	int last = -999;
	for (int i = 0; i < scheduledCount; i++)
	{
		if (cNo[i] != last)
		{
			cout << scheduledSections[i].prefix << " " << cNo[i] << endl;
			cout << "--------" << endl;
			for (int j = 0; j < scheduledCount; j++)
			{
				if (scheduledSections[j].course_number == cNo[i])
				{
					cout << "Course ID: " << scheduledSections[j].section_id << endl;
					cout << "Section #: " << setfill('0') << setw(2) << scheduledSections[j].section_num << endl;
					cout << "# Students: " << scheduledSections[j].num_students << endl;
					cout << "Room: " << scheduledSections[j].room.building_code << " " << scheduledSections[j].room.room_number << endl;
					cout << "Capacity: " << scheduledSections[j].room.max_students << endl;
					cout << "Meeting Day/Time: " << printDays(scheduledSections[j].days) << " ";
					cout << setfill('0') << setw(4) << scheduledSections[j].startTime << "-" << setfill('0') << setw(4) << scheduledSections[j].endTime << endl << endl;
				}
			}
			last = cNo[i];
		}
	}
}

void printScheduledSections()
{
	cout << "SCHEDULE BY CLASSROOM" << endl;
	cout << "---------------------" << endl << endl;

	for (int i = 0; i < roomCount; i++)
	{
		cout << allRooms[i].building_code << " " << allRooms[i].room_number << ", CAPACITY=" << allRooms[i].max_students << endl;
		cout << "-------" << endl;
		for (int j = 0; j < scheduledCount; j++)
		{
			if (roomsMatch(scheduledSections[j].room, allRooms[i]))
			{
				cout << printDays(scheduledSections[j].days) << " ";
				cout << setfill('0') << setw(4) << scheduledSections[j].startTime << "-" << setfill('0') << setw(4) << scheduledSections[j].endTime << " ";
				cout << scheduledSections[j].prefix << " " << scheduledSections[j].course_number << " ";
				cout << setfill('0') << setw(2) << scheduledSections[j].section_num << " " << scheduledSections[j].section_id << " ";
				cout << "NUM_STUDENTS=" << scheduledSections[j].num_students << endl;
			}
		}
		cout << endl;
	}
}

//You will have to implement the methods roomsMatch, daysMatch, fixTime

bool scheduleSections()
{
	//Schedule sections from largest room to smallest room - in section size
	//Schedule all classes that can only fit in the largest room, that hasn't
	//yet been scheduled (starting with the largest room). When that is done
	//go to the next largest room, etc. 
	//This function assumes the rooms array is sorted from largest room to
	//smallest room.
	//roomCount is the total number of rooms that exist
	scheduledSections = new Scheduled_Sections[sectionCount];

	int *allSizes = new int[roomCount + 1];
	int *iPos = new int[roomCount + 1];
	allSizes[0] = 0;
	iPos[0] = 0;

	for (int i = 1; i <= roomCount; i++)
	{
		allSizes[i] = allRooms[i - 1].max_students;
		iPos[i] = i - 1;
	}

	for (int i = 0; i <= roomCount; i++)
	{
		int min = allSizes[i], pos = i;
		for (int j = i + 1; j < roomCount + 1; j++)
		{
			if (min > allSizes[j])
			{
				min = allSizes[j];
				pos = j;
			}
		}
		int temp = allSizes[i];
		allSizes[i] = allSizes[pos];
		allSizes[pos] = temp;
		temp = iPos[i];
		iPos[i] = iPos[pos];
		iPos[pos] = temp;
	}

	for (int i = 0; i< roomCount; i++) {
		//Use roomCount-1, since we check two room size values at a time
		int bigRoomSize = allSizes[i + 1];
		int smallRoomSize = allSizes[i];

		//We want to schedule all the rooms that have a size greater than
		//smallRoomSize and less than or equal to bigRoomSize
		for (int j = 0; j< sectionCount; j++) {
			if (allSections[j].num_students > smallRoomSize &&
				allSections[j].num_students <= bigRoomSize) {
				//This is a room we are to schedule
				bool scheduled = scheduleAvailable(allSections[j], iPos[i + 1]);
				if (!scheduled) {
					//Have at least one section that cannot be scheduled
					cout << endl;
					cout << "There's at least one room that can't be scheduled." << endl;
					cout << endl;
					return false;
				}
			}
		}
	}

	return true;
}

bool scheduleAvailable(Section sectionToSchedule, int roomIndex) 
{
	int* constraintDays = sectionToSchedule.constraints.days; // see explanation below 
	int constraintStartTime = sectionToSchedule.constraints.earliest_start_time;
	int originalStartTime = constraintStartTime;
	int constraintEndTime = sectionToSchedule.constraints.latest_end_time;
	int courseLength = sectionToSchedule.course.num_minutes;
	int currentScheduledCount = scheduledCount;
	int sectNum = sectionToSchedule.section_number;
	Course course = sectionToSchedule.course;
	int numStudents = sectionToSchedule.num_students;

	bool canSchedule = false;
	int scheduleRoomIndex = roomIndex;
	int actualStartTime = constraintStartTime;
	int k = 0;

	while (k < scheduledCount) 
	{
		if (canSchedule) {
			//We can schedule, so exit the for loop
			break;
		}

		//Check if there is a conflict with an already scheduled section
		Scheduled_Sections scheduledSection = scheduledSections[k];
		int scheduledStartTime = scheduledSection.startTime;
		int scheduledEndTime = scheduledSection.endTime;
		int* scheduledDays = scheduledSection.days;
		Room scheduledRoom = scheduledSection.room;

		actualStartTime = constraintStartTime;

		int possibleStartTime = constraintStartTime;

		while (true) {
			if (scheduleRoomIndex < 0) {
				//Have tried all the rooms. This section cannot be scheduled
				canSchedule = false;
				break;
			}

			if (roomsMatch(scheduledRoom, allRooms[scheduleRoomIndex])) {
				//The needed room matches the already scheduled room
				if (daysMatch(scheduledDays, constraintDays)) {
					//Days match. Check the times. If the days don't match, no overlap.
					possibleStartTime = timesOverlap(scheduledStartTime, scheduledEndTime,
						actualStartTime, constraintEndTime,
						courseLength);
					if (possibleStartTime != actualStartTime) {
						//The start time has changed, we must start over with
						//checking scheduled sections, using this new start tim,
						//only if the end time is within the constraintEndTime
						if (fixTime(possibleStartTime, courseLength + 10) >
							constraintEndTime) {
							//This section cannot be scheduled in this room. Try the next
							//bigger room, and start with the first scheduled section
							possibleStartTime = originalStartTime;
							scheduleRoomIndex--;
							break;
						}

						//The new end time is within the constraint end time, so we 
						//exit the while loop, set k back to 0, and try the new times
						//against all the scheduled sections
						break;
					}

					if (actualStartTime == -1) {
						//Cannot schedule in this room. Try the next biggest room
						actualStartTime = originalStartTime;
						scheduleRoomIndex--;
						continue;
					}

					break;
				}
			}

			//Current scheduled section does not overlap the needed section. Try the
			//next scheduled section
			break;
		} //end of while

		//Must increment k since we have a for loop now
		k++;

		if (possibleStartTime != actualStartTime) {
			//Must start over using this new start time
			canSchedule = false;
			constraintStartTime = possibleStartTime;
			k = 0;
		}
	} //end of for

	if ((scheduledCount == 0 || scheduledCount == k) && scheduleRoomIndex != -1) {
		//No scheduled sections, so we can schedule, OR we went through all the
		//sections and found a schedulable time
		canSchedule = true;
	}

	if (canSchedule) {
		//We can scheule this section. So do it.
		scheduledSections[scheduledCount].startTime = actualStartTime;
		scheduledSections[scheduledCount].section_id = sectionToSchedule.section_id;
		scheduledSections[scheduledCount].prefix = course.prefix;
		scheduledSections[scheduledCount].course_number = course.course_number;
		scheduledSections[scheduledCount].endTime = fixTime(actualStartTime,
			course.num_minutes);
		scheduledSections[scheduledCount].room = allRooms[scheduleRoomIndex];
		scheduledSections[scheduledCount].num_students = numStudents;
		scheduledSections[scheduledCount].section_num = sectNum;

		for (int i = 0; i<7; i++) {
			//Copy the day values
			scheduledSections[scheduledCount].days[i] = constraintDays[i];
		}
		scheduledCount++;
	}

	return canSchedule;
}

int timesOverlap(int scheduledStartTime, int scheduledEndTime, int constraintStartTime, int constraintEndTime, int numMinutes) {
	//Looking for a start time and end time, for the current class, that does
	//not overlap the scheduled start and end time, that are provided
	//Returns -1 if we cannot find a time. Otherwise returns the schedulable start time
	bool scheduled = false;
	while (!scheduled) {
		if ((constraintStartTime >= scheduledStartTime &&
			constraintStartTime <= scheduledEndTime) ||
			(fixTime(constraintStartTime, numMinutes) >= scheduledStartTime &&
			fixTime(constraintStartTime, numMinutes) <= scheduledEndTime)) {
			//Can't start the new section at this time.
			//Advance the start time by numMinutes plus 10 minutes and return.
			//We must now compare this new start time with all scheduled sections
			return fixTime(constraintStartTime, numMinutes + 10);
		}
		else {
			//This is a possible scheduable start time. We must use the new times for future
			//schedule checks
			break;
		}
	}

	return constraintStartTime;
}

int fixTime(int actualStartTime, int num_minutes)
{
	int extraStartTime = actualStartTime % 100;
	actualStartTime -= extraStartTime;
	num_minutes += extraStartTime;
	while (num_minutes > 60)
	{
		actualStartTime += 100;
		num_minutes -= 60;
	}

	return (actualStartTime + num_minutes);
}

bool daysMatch(int *scheduledDays, int *constraintDays)
{
	for (int i = 0; i < 7; i++)
		if (scheduledDays[i] != constraintDays[i])
			return false;
	return true;
}

bool roomsMatch(Room scheduledRoom, Room thisRoom)
{
	return (strcmp(scheduledRoom.building_code, thisRoom.building_code) == 0 && (scheduledRoom.room_number == thisRoom.room_number));
}