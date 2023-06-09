
#include "ringbuffer.h"





RingBuffer::RingBuffer(quint32 _size, QObject *parent)
    : QObject(parent),
      size(_size)
{
    mask = size - 1;
    fbuf = (char*) malloc(sizeof(char) * size);
    clean();
}

RingBuffer::~RingBuffer()
{
    free(fbuf);
}

void RingBuffer::clean()
{
    idxRead = 0;
    idxWrite = 0;
    dataCount = 0;
}

bool RingBuffer::write(char *data, quint32 len)
{
    if(availableWrite() < len)
        return false;

    dataCount += len;

    for(int i = 0; i < len; i++)
    {
        fbuf[idxWrite++] = data[i];
        idxWrite &= mask;
    }

    return true;
}

bool RingBuffer::read(char *data, quint32 len)
{
    if(availableRead() < len)
        return false;

    dataCount -= len;

    for(int i = 0; i < len; i++)
    {
        data[i] = fbuf[idxRead++];
        idxRead &= mask;
    }

    return true;
}

float RingBuffer::getSample()
{
    dataCount --;
    float sample = fbuf[idxRead++];
    idxRead &= mask;
    return sample;
}

void RingBuffer::addSample(char sample)
{
    dataCount ++;
    fbuf[idxWrite++] = sample;
    idxWrite &= mask;
}

quint32 RingBuffer::availableRead()
{
    return dataCount;
}

quint32 RingBuffer::availableWrite()
{
    return size - dataCount;
}

