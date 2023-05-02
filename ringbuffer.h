#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <QObject>




class RingBuffer : public QObject
{
    Q_OBJECT

public:
    explicit RingBuffer(quint32 _size, QObject *parent = nullptr);
    ~RingBuffer();

    void clean();
    bool read(char *data, quint32 len);
    bool write(char *data, quint32 len);
    float getSample();
    void addSample(char sample);
    quint32 availableRead(); // available size read data
    quint32 availableWrite(); // available size write data

private:
    quint32 size;
    quint32 mask;
    quint32 idxRead;
    quint32 idxWrite;
    quint32 dataCount; // available read data size
    char *fbuf = nullptr;
};


#endif // RINGBUFFER_H
