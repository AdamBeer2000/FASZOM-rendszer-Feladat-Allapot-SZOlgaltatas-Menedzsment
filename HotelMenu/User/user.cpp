#include "user.h"

std::string Users::User::getFirstName() const
{
    return firstName;
}

std::string Users::User::getLastName() const
{
    return lastName;
}

std::string Users::User::getUsername() const
{
    return username;
}

date Users::User::getBirthDate() const
{
    return birthDate;
}

Users::jobs Users::User::getJobID() const
{
    return jobID;
}

int Users::User::getCardID() const
{
    return cardID;
}

std::string Users::User::getPassword() const
{
    return password;
}

int Users::User::getRoomId(std::string taskid)
{
    return taskCont.getRoomId(taskid);
}

Tasks::Task Users::User::getTask(std::string taskId)
{
    return taskCont.getTask(taskId);
}

Reservation Users::User::getReserv(std::string task_id)
{
    return taskCont.getReserv(task_id);
}

int Users::User::getNumberOfTasks() const
{
    return taskCont.getActiveTasksNumber();
}

//ezt eddig miért nem jelezte hibának hogy nem voltak itt?
void Users::User::setLog(const std::string &task_id, Logs::Log *onelog)
{
    taskCont.setLog(task_id,onelog);
}

void Users::User::addTask(Tasks::Task oneTask)
{
    taskCont.addTask(oneTask);
}

void Users::User::deleteTask(std::string &TaskId)
{
    taskCont.deleteTask(TaskId);
}

Users::User::User()
{

}

Users::User::User(const std::string &_firstName, const std::string &_lastName, const std::string &_username, date _birthDate, Users::jobs _jobID, int _cardID, const std::string &_password):
    firstName(_firstName),
    lastName(_lastName),
    username(_username),
    birthDate(_birthDate),
    jobID(_jobID),
    cardID(_cardID),
    password(_password)
{
    taskCont=TaskContainer();
}

Users::User::~User()
{

}

void Users::User::saveAlltask(std::ofstream & myesfile)
{
    taskCont.saveStuff(myesfile);
}
